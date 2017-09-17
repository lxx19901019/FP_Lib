/* In this file we define certain useful constants, including parameters/precision/etc... */

/* ASSUMPTIONS:

   compiler needs to use:

   --arithmetic right-shift
   --2's complement 

   Processor needs to:

   --conform to IEEE standard for floating point arithmetic

*/

#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

typedef int32_t fp_32;

/* Basic Arithmetic */
fp_32 fp32_add(fp_32, fp_32);
fp_32 fp32_sub(fp_32, fp_32);
fp_32 fp32_mult(fp_32, fp_32);   
fp_32 fp32_div(fp_32, fp_32);

/* Basic Conversion */
fp_32 int32_to_fp32(int32_t);
int32_t fp32_trunc_to_int32(fp_32);
int32_t fp32_round_to_int32(fp_32);
fp_32 float_to_nearest_fp32(float);
float fp32_to_nearest_float(fp_32);
fp_32 double_to_nearest_fp32(float);
float fp32_to_nearest_double(fp_32);


/* Min/Max */
fp_32 fp32_min(fp_32*); /* Should return the indices of the max/min values */
fp_32 fp32_max(fp_32*);


/**************  TODO TODO:

Saturating Arithmetic: TO IMPLEMENT LATER...LOOK AT WIKI 

***************/


/* Exponential Functions */
fp_32 fp32_sqrt(fp_32);
fp_32 fp32_nat_exp(fp_32);
fp_32 fp32_gen_exp(fp_32, fp_32);
fp_32 fp32_nat_log(fp_32);
fp_32 fp32_gen_log(fp_32, fp_32);

/* 
   Trigonometric Functions. Implemented via Taylor Polynomials Currently. 
   Number Of Iterations Set in Parameters Header: should solve instead for    
 */
fp_32 fp32_sin(fp_32);
fp_32 fp32_cos(fp_32);
fp_32 fp32_tan(fp_32);

fp_32 fp32_asin(fp_32);
fp_32 fp32_acos(fp_32);
fp_32 fp32_atan(fp_32);

/* Eh...Include parameters here anyway since they will be necessary.  */

/* Will include optimization definitions for */



/************ IEEE FLOATING POINT CONSTANTS **********************/

/* sign bit is always one in either precision, no point in coding it */

const int 


/************ END IEEE FLOATING POINT CONSTANTS ******************/


/* FRAC_P is the number of decimal bits we wish to sacrifice for
   fractional precision: so the smallest quantity representable in our
   representation is 2^(-FRAC_P).

   For now split evenly, but beware of the ranges derived from this fact. */
const int FRAC_P = 16;


/* Create a bit-mask for easy selection */
const int FRAC_MASK = (1 << FRAC_P) - 1;

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








