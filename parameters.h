#include <limits.h>

/* Will include optimization definitions for */


/* FRAC_P is the number of decimal bits we wish to sacrifice for
   fractional precision: so the smallest quantity representable in our
   representation is 2^(-FRAC_P).

   For now split evenly, but beware of the ranges derived from this fact. */
const int FRAC_P 16;

/*
   >> the overflow bound is exclusive: fp_32 can represent *up to* this bound.
   >> the underflow bound is inclusive: FP32_UNDERFLOW is the largest magn. 
      negative number we may implement
  */
const int32_t FP32_OVERFLOW = 1 << (31 - FRAC_P);
const int32_t FP32_UNDERFLOW = -FP32_OVERFLOW;

/* In general, should not use macros where constants will do. */
const int NUM_NEWT_ITER = 20;



/*
   FOR EXPONENT BOUNDS... NEED TO FIX BASED ON FRAC_P PRECISION. 
   THIS IS KEY FOR CHANGING THE RANGE OF FRACTIONAL PRECISION LATER:
   HAVE TO CHANGE THESE CONSTANTS AS WELL

   for FRAC_P = 16, FP32_OVERFLOW = 2^15

   ==> 

   log_e(2^15) = 15 * log_e(2) == FILL OUT

*/
const int MAX_EXP_INP_16 = ;

const int NUM_EXP_TERM_APPROX








