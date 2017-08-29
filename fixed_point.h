/* In this file we define certain useful constants, including */

#include <stdint.h>

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
