/* In this file we define certain useful constants, including */

#include <stdint.h>

#include <inttypes.h>

/* Define the desired level of fractional precision...for now split evenly, but beware
   of the ranges derived from this fact. */
#define FRAC_P 16

typedef int32_t fp_32;

/* The idea here with static is that we do not want references to these constants
   outside of *this* compilation unit. */
static const fp_32_OVERFLOW // TODO TODO
static const fp_32_UNDERFLOW

/* Basic Conversion */
fp_32 int32_to_fp32(int32_t);
int32_t fp32_to_nearest_int32(fp_32);
int32_t fp32_to_lower_int32(fp_32);
fp_32 float_to_fp32(float);
float fp32_to_float(fp_32);

fp_32 fp32_add(fp_32, fp_32);
fp_32 fp32_sub(fp_32, fp_32);
fp_32 fp32_mult(fp_32, fp_32);
fp_32 fp32_div(fp_32, fp_32);


/* Min/Max */
fp_32 fp32_min(fp_32*); /* Should return the indices of the max/min values */
fp_32 fp32_max(fp_32*);


/**************  TODO TODO:

Saturating Arithmetic: TO IMPLEMENT LATER...LOOK AT WIKI 

***************/


/* Exponential Functions */
fp_32 fp32_sqrt(fp_32);
fp_32 fp32_nat_exp(fp_32);
fp_32 fp32_nat_log(fp_32);
fp_32 fp32_gen_exp(fp_32, fp_32);
fp_32 fp32_gen_log(fp_32, fp_32);

/* Trigonometric Functions. 

   IDEA: Include a s
 */
fp_32 fp32_sin(fp_32);
fp_32 fp32_cos(fp_32);

