/*
    Copyright (C) 2023 Jean Kieffer

    This file is part of Arb.

    Arb is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "acb_theta.h"

static void
acb_theta_naive_round(arb_ptr a, arb_srcptr v, slong g)
{
    slong j;

    for (j = 0; j < g; j++)
    {
        if (!arb_is_finite(&v[j])
            || arf_cmpabs_ui(arb_midref(&v[j]), WORD_MAX) > 0)
        {
            flint_printf("acb_theta_naive_reduce: Error (impossible rounding)\n");
            arb_printd(&v[j], 10);
            flint_printf("\n");
            fflush(stdout);
            flint_abort();
        }
        arb_set_si(&a[j], arf_get_si(arb_midref(&v[j]), ARF_RND_NEAR));
    }
}

static void
_arb_vec_union(arb_ptr res, arb_srcptr v1, arb_srcptr v2, slong len, slong prec)
{
    slong j;

    for (j = 0; j < len; j++)
    {
        arb_union(&res[j], &v1[j], &v2[j], prec);
    }
}

static void
acb_theta_naive_reduce_one(arb_ptr v, acb_ptr new_z, acb_t c, arb_t u,
    acb_srcptr z, const arb_mat_t X, const arb_mat_t Y,  const arb_mat_t Yinv,
    const arb_mat_t C, slong prec)
{
    slong g = arb_mat_nrows(X);
    arb_ptr x, y, a, t, r, new_x, new_y;

    x = _arb_vec_init(g);
    y = _arb_vec_init(g);
    a = _arb_vec_init(g);
    t = _arb_vec_init(g);
    r = _arb_vec_init(g);
    new_x = _arb_vec_init(g);
    new_y = _arb_vec_init(g);

    acb_zero(c);
    _acb_vec_get_real(x, z, g);
    _acb_vec_get_imag(y, z, g);

    /* Get center t = Yinv y of ellipsoid, set c = - i y^T Yinv y and u */
    arb_mat_vector_mul_col(t, Yinv, y, prec);
    arb_dot(acb_imagref(c), acb_imagref(c), 1, y, 1, t, 1, g, prec);

    arb_const_pi(u, prec);
    arb_mul(u, u, acb_imagref(c), prec);
    arb_neg(u, u);
    arb_exp(u, u, prec);

    /* Round to nearest even integer vector a to not mess with characteristics */
    _arb_vec_scalar_mul_2exp_si(t, t, g, -1);
    acb_theta_naive_round(a, t, g);
    _arb_vec_scalar_mul_2exp_si(a, a, g, 1);
    _arb_vec_scalar_mul_2exp_si(t, t, g, 1);

    /* Get r = t - a and v = C.r */
    _arb_vec_sub(r, t, a, g, prec);
    arb_mat_vector_mul_col(v, C, r, prec);

    /* new_z is (x - Xa) + iYr; set new_y = Yr and t = Xa */
    arb_mat_vector_mul_col(t, X, a, prec);
    _arb_vec_sub(new_x, x, t, g, prec);
    arb_mat_vector_mul_col(new_y, Y, r, prec);
    _acb_vec_set_real_imag(new_z, new_x, new_y, g);

    /* add a^T X a - 2 a^T x + i r^T Y r to c */
    arb_dot(acb_realref(c), acb_realref(c), 0, a, 1, t, 1, g, prec);
    _arb_vec_scalar_mul_2exp_si(a, a, g, 1);
    arb_dot(acb_realref(c), acb_realref(c), 1, a, 1, x, 1, g, prec);
    arb_dot(acb_imagref(c), acb_imagref(c), 0, r, 1, new_y, 1, g, prec);

    acb_exp_pi_i(c, c, prec);

    _arb_vec_clear(x, g);
    _arb_vec_clear(y, g);
    _arb_vec_clear(a, g);
    _arb_vec_clear(t, g);
    _arb_vec_clear(r, g);
    _arb_vec_clear(new_x, g);
    _arb_vec_clear(new_y, g);
}

void
acb_theta_naive_reduce(arb_ptr v, acb_ptr new_zs, acb_ptr cs, arb_ptr us,
    acb_srcptr zs, slong nb, const acb_mat_t tau, const arb_mat_t C, slong prec)
{
    slong g = acb_mat_nrows(tau);
    arb_mat_t X, Y, Yinv;
    arb_ptr v1;
    slong k;

    arb_mat_init(X, g, g);
    arb_mat_init(Y, g, g);
    arb_mat_init(Yinv, g, g);
    v1 = _arb_vec_init(g);

    acb_mat_get_real(X, tau);
    acb_mat_get_imag(Y, tau);
    arb_mat_inv(Yinv, Y, prec);

    for (k = 0; k < nb; k++)
    {
        acb_theta_naive_reduce_one(v1, new_zs + k * g, &cs[k], &us[k],
            zs + k * g, X, Y, Yinv, C, prec);
        if (k == 0)
        {
            _arb_vec_set(v, v1, g);
        }
        else
        {
            _arb_vec_union(v, v, v1, g, prec);
        }
    }

    arb_mat_clear(X);
    arb_mat_clear(Y);
    arb_mat_clear(Yinv);
    _arb_vec_clear(v1, g);
}
