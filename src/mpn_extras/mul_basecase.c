/*
    Copyright (C) 2023 Albin Ahlbäck

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include "mpn_extras.h"

#if FLINT_HAVE_ADX

mp_limb_t flint_mpn_mul_1_1(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_2_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_2_2(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_3_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_3_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_3_3(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_4_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_4_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_4_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_4_4(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_5_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_5_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_5_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_5_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_5_5(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_6_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_6(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_7_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_7(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_8_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_9_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_10_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_11_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_12_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_13_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_14_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_15_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_16_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_8(mp_ptr, mp_srcptr, mp_srcptr);

#define _MUL(mx, nx) flint_mpn_mul_##mx##_##nx
#define MUL(mx, nx) _MUL(mx, nx)

static mp_limb_t (* mul_funcs[][8])(mp_ptr, mp_srcptr, mp_srcptr) =
{
    {MUL( 1,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {MUL( 2,1), MUL( 2,2),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {MUL( 3,1), MUL( 3,2), MUL( 3,3),      NULL,      NULL,      NULL,      NULL,      NULL},
    {MUL( 4,1), MUL( 4,2), MUL( 4,3), MUL( 4,4),      NULL,      NULL,      NULL,      NULL},
    {MUL( 5,1), MUL( 5,2), MUL( 5,3), MUL( 5,4), MUL( 5,5),      NULL,      NULL,      NULL},
    {MUL( 6,1), MUL( 6,2), MUL( 6,3), MUL( 6,4), MUL( 6,5), MUL( 6,6),      NULL,      NULL},
    {MUL( 7,1), MUL( 7,2), MUL( 7,3), MUL( 7,4), MUL( 7,5), MUL( 7,6), MUL( 7,7),      NULL},
    {MUL( 8,1), MUL( 8,2), MUL( 8,3), MUL( 8,4), MUL( 8,5), MUL( 8,6), MUL( 8,7), MUL( 8,8)},
    {MUL( 9,1), MUL( 9,2), MUL( 9,3), MUL( 9,4), MUL( 9,5), MUL( 9,6), MUL( 9,7), MUL( 9,8)},
    {MUL(10,1), MUL(10,2), MUL(10,3), MUL(10,4), MUL(10,5), MUL(10,6), MUL(10,7), MUL(10,8)},
    {MUL(11,1), MUL(11,2), MUL(11,3), MUL(11,4), MUL(11,5), MUL(11,6), MUL(11,7), MUL(11,8)},
    {MUL(12,1), MUL(12,2), MUL(12,3), MUL(12,4), MUL(12,5), MUL(12,6), MUL(12,7), MUL(12,8)},
    {MUL(13,1), MUL(13,2), MUL(13,3), MUL(13,4), MUL(13,5), MUL(13,6), MUL(13,7), MUL(13,8)},
    {MUL(14,1), MUL(14,2), MUL(14,3), MUL(14,4), MUL(14,5), MUL(14,6), MUL(14,7), MUL(14,8)},
    {MUL(15,1), MUL(15,2), MUL(15,3), MUL(15,4), MUL(15,5), MUL(15,6), MUL(15,7), MUL(15,8)},
    {MUL(16,1), MUL(16,2), MUL(16,3), MUL(16,4), MUL(16,5), MUL(16,6), MUL(16,7), MUL(16,8)},
};

/* NOTE: Important that the inputs are in this order to avoid additional moves
 * when calling `mul_funcs'. */
mp_limb_t
flint_mpn_mul_basecase(mp_ptr res, mp_srcptr ap, mp_srcptr bp, slong alen, slong blen)
{
    FLINT_ASSERT(alen >= blen);
    FLINT_ASSERT(blen >= 1);
    FLINT_ASSERT(alen <= 32);

    if (alen <= 16 && blen <= 8)
    {
        return mul_funcs[alen - 1][blen - 1](res, ap, bp);
    }
    else if (alen <= 16)
    {
        /* 1 <= m <= 16, 8 < n <= m */
        /* Calculate a * [b0, b1] */
        return 0;
    }
    else if (blen <= 8)
    {
        /* 16 < m <= 32, 1 <= n <= 8 */
        /* Calculate [a0, a1] * b */
        return 0;
    }
    else if (alen <= 16)
    {
        /* 16 < m <= 32, 8 < n <= m */
        /* Calculate [a0, a1] * [b0, b1] */
        return 0;
    }
}

#else

typedef int this_file_is_empty;

#endif