/*
    Copyright (C) 2012 Fredrik Johansson

    This file is part of Arb.

    Arb is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include <mpfr.h>
#include "arb.h"

int main()
{
    slong iter;
    flint_rand_t state;

    flint_printf("const_euler....");
    fflush(stdout);
    flint_randinit(state);

    for (iter = 0; iter < 250 * 0.1 * flint_test_multiplier(); iter++)
    {
        arb_t r;
        mpfr_t s;
        slong accuracy, prec;

        flint_set_num_threads(1 + n_randint(state, 3));

        prec = 2 + n_randint(state, 1 << n_randint(state, 16));

        arb_init(r);
        mpfr_init2(s, prec + 1000);

        arb_const_euler(r, prec);
        mpfr_const_euler(s, MPFR_RNDN);

        if (!arb_contains_mpfr(r, s))
        {
            flint_printf("FAIL: containment\n\n");
            flint_printf("prec = %wd\n", prec);
            flint_printf("r = "); arb_printd(r, prec / 3.33); flint_printf("\n\n");
            flint_abort();
        }

        accuracy = arb_rel_accuracy_bits(r);

        if (accuracy < prec - 4)
        {
            flint_printf("FAIL: poor accuracy\n\n");
            flint_printf("prec = %wd\n", prec);
            flint_printf("r = "); arb_printd(r, prec / 3.33); flint_printf("\n\n");
            flint_abort();
        }

        arb_clear(r);
        mpfr_clear(s);
    }

    flint_randclear(state);
    flint_cleanup_master();
    flint_printf("PASS\n");
    return 0;
}