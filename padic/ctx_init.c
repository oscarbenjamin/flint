/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2011 Sebastian Pancratz
 
******************************************************************************/

#include "padic.h"

void padic_ctx_init(padic_ctx_t ctx, const fmpz_t p, long N, 
                    enum padic_print_mode mode)
{
    fmpz_init(ctx->p);
    fmpz_set(ctx->p, p);

    ctx->N = N;

    ctx->pinv = (!COEFF_IS_MPZ(*p)) ? n_precompute_inverse(fmpz_get_ui(p)) : 0;

    if (N > 0)
    {
        long i, len;

        ctx->min = FLINT_MAX(1, N - 10);
        ctx->max = N + 10;
        len      = ctx->max - ctx->min;

        ctx->pow = _fmpz_vec_init(len);

        fmpz_pow_ui(ctx->pow, p, ctx->min);
        for (i = 1; i < len; i++)
            fmpz_mul(ctx->pow + i, ctx->pow + (i - 1), p);
    }
    else
    {
        ctx->min = 0;
        ctx->max = 0;
        ctx->pow = NULL;
    }

    ctx->mode = mode;
}

