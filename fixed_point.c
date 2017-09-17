#include "fixed_point.h"
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> /* For floating-point specifications */

/* 

BASED UPON

code.google.com/archive/p/libfixmath/source/default/source


--DO NOT INCLUDE COMPLEX NUMBERS
 
--CREATE README DOCUMENTATION

--UNDERFLOW/OVERFLOW DETECTION

REMEMEBER: Underflow refers to the LARGEST NEGATIVE VALUE occuring, NOT a loss
in precision due to fractional components smaller than 2^{-FRAC_P}

--HARDCODE CERTAIN CONSTANTS



NOTE: this code, due to the floating-point specification extraction, 
can only be compiled with the GNU compiler. 

*/

/* NECESSARY CONSTANT DEFINITIONS */

//TODO 
// const int32_t fp_32_OVERFLOW ;
// const int32_t fp_32_UNDEFLOW ; 


/* Contains operations for fixed_point arithmetic. 

  Just implement the basics.

  IMPLEMENT THE BASICS

  IMPLEMENT THE BASICS AND ITERATE

  GET SOMETHING WORKING THEN ITERATE THEN ITERATE THEN ITERATE 

 */


/********** BEGIN BASIC ARITHMETIC **********/

/* Overflow detection is built-in to all these functions. */

/* Returns a + b in fixed point. See "Addition" in README.pdf
   for further details.  */
fp_32 fp32_add(fp_32 a, fp_32 b)
{
  if (a < 0 && b < 0 && a + b > 0)
    {
      fprintf(stderr, "fp32_add Underflow");
      exit(1);
    }

  else if (a > 0 && b > 0 && a + b < 0)
    {
      fprintf(stderr, "fp32_add Overflow");
      exit(1);
    }

  else
    {
      return a + b;
    }
}

/* For fp's "a" and "b", returns a - b

   NOTE: order of input diverges from the IA32 standard. */
fp_32 fp32_sub(fp_32 a, fp_32 b)
{
  if (a < 0 && b > 0 && a + b > 0)
    {
      fprintf(stderr, "fp32_sub Underflow");
      exit(1);
    }

  else if (a > 0 && b < 0 && a + b < 0)
    {
      fprintf(stderr, "fp32_sub Overflow");
      exit(1);
    }

  else
    {
      return a - b;
    }
}

/* For fp's "a" and "b", returns "a * b" in fixed point. */
fp_32 fp32_mult(fp_32 a, fp_32 b)
{

  /* OK... so now this is in 64-bit.   */
  int64_t temp = (int64_t a) * (int64_t b);

  /* 2 * FRAC_P bits in the result will be fractional...the rest will be 
     integral. So can check for overflow/underflow/loss of precision this way.  */

  if (temp > (int64_t FP32_OVERFLOW))
    {
      fprintf(stderr, "fp32_mult Overflow/Underflow");
      exit(1);
    }

  /* If any of the last FRAC_P fractional bits are set, 
     we have lost precision and should be flagged accordingly.
     
     PROBABLY should not worry about this...just come back and comment out later.
 */
  else if ((temp & FRAC_MASK) != 0)
    {
      fprintf(stderr, "fp32_mult precision loss");
      exit(1);
    }
  
  /* Otherwise...return the truncated right shift. Using gnu compiler so this is
     guaranteed to be arithmetic */
  else
    {
      return (fp_32) (temp >> FRACP_P);
    }
 
}

/* For fp's "a" and "b", returns a/b

   NOTE: order of input diverges from the IA32 standard. */
fp_32 fp32_div(fp_32 a, fp_32 b)
{
  /* OK... so now this is in 64-bit.   */
  int64_t temp = (((int64_t) a) << FRAC_P) / (int64_t b);

  /* Overflow and underflow can occur here...and a loss of precision
     quite easily as well. Way to check with division, however, is 
     the result in 64-bit vs the result in 32-bit. */
  if (temp > (int64_t FP32_OVERFLOW))
    {
      fprintf(stderr, "fp32_mult Overflow");
      exit(1);
    }

  /* Otherwise...return the truncated right shift. Using gnu compiler so this is
     guaranteed to be arithmetic */
  else
    {
      return (fp_32) (temp);
    }
  
}


/********** END BASIC ARITHMETIC  ***********/


/********** BEGIN BASIC CONVERSIONS  ***********/

/* 
   Converts a 32-bit integer to the corresponding 
   32-bit fixed_point type. 

   WARNING: Overflow/Underflow may occur, which results
   in printing to stderr
*/
fp_32 int32_to_fp32(int32_t int32_input)
{
  /* 
     Overflow/Underflow occurs in a very specific case: if int_input
     falls outside the range:
  
     FP32_UNDERFLOW <= int_input < FP32_OVERFLOW
  */
  if (int32_input < FP32_UNDERFLOW || int32_input >= FP32_OVERFLOW)
    {
      fprintf(stderr, "Error: Overflow/Underflow on integer to fp_32 conversion.");
      exit(1);
    }
  
  else
    {
      return (fp_32) (in32_input << FRAC_P);
    }

}

/* 
   Converts an fp_32 to a 32-bit integer via
   naive truncation. 

   No error is possible here really, but a loss
   of precision is more or less guaranteed. 
*/
int32_t fp32_trunc_to_int32(fp_32 fp32_input)
{
  return (in32_t) (fp32_input >> FRAC_P);
}


/* 
   Rather than truncate the fp_32, this rounds
   it to the nearest integer.

   METHOD: If positive, add 1/2. If negative, subtract
   1/2. Return the truncation of the sum in both cases. 

   No error possible.  
 */
int32_t fp32_round_to_int32(fp_32 fp32_input)
{
  return (((int32_t)fp_32) < 0) ?
     
    (fp32_input - (1 << (FRAC_P - 1))) >> FRAC_P :

    (fp32_input + (1 << (FRAC_P - 1))) >> FRAC_P;
    
}

/* A bit more complicated now...need to somehow extract the specs for the floating
   point on the compiler. 

   See:

 https://www.gnu.org/savannah-checkouts/gnu/libc/manual/html_node/Floating-Point-Parameters.html

   For the source on the specifications for floating point in "float.h" . 


   Method employed:

   1. Multiply the float by 2^(FLT_MANT_DIG), to retrieve a full 


   THINK ABOUT WHEN PRECISION IS LOST HERE. FOLLOWING LINK SHOULD BE HELPFUL


https://stackoverflow.com/questions/15685181/how-to-get-the-sign-mantissa-and-exponent-of-a-floating-point-number

   

*/
fp_32 float_to_nearest_fp32()
{

  /* Value of the radix in the gcc representation: always 2. */
  FLT_RADIX;

  /* The number of digits in the mantissa:  */
  FLT_MANT_DIG;

  /* */
}

fp_32 fp32_to_nearest_float()
{

}


/********** END BASIC CONVERSIONS  ***********/


/********** BEGIN SATURATING ARITHMETIC  ***********/





/********** END SATURATING  ARITHMETIC  ***********/



/********** BEGIN EXPONENTIAL FUNCTIONS **********/

/* Applies Newton's Method for an arbitrary # of iterations set in parameters.h

   The recursive relation used is:
     
   x_{n+1} = ((x_n)^2 + r) / (2 * x_n)

   Throws an error if fp32_inp < 0. 
 */
fp_32 fp32_sqrt(fp_32 fp32_inp)
{
  /* Necessary variables. Thinking about how C works... only need one 
     x iterator really.  */
  fp_32 x_curr;
  int i;

  /* 
     We have the updating relation:
     
     x_curr = ((x_curr)^2 + r) / (2 * x_curr)

     numerator and denominator are just for breaking 
     apart the above computation and increasing readability. 
 */
  fp_32 numerator, denominator;
  
  /* NUM_NEWT_ITER is the relevant optimization parameter here.  */
  if (fp32_inp < 0)
    {
      fprintf(stderr, "Error: Negative input to fp32_sqrt");
      exit(1);
    }

  else if(fp32_inp == 0)
    {
      return (fp_32) 0;
    }

  /* Where Newton's Approximation is performed. */
  else
    {
      /* Just initialize to the input divided by two: should be close enough
         but perhaps should test/tweak. REMEMBER: ALWAYS CAST THE INTEGERS PRIOR
         TO USING THEM (in this case, 2). */
      x_curr = fp32_div(fp32_inp, (fp_32) 2);

      /* Just compute the above formula for a fixed # of times. */
      for (i = 0; i < NUM_NEWTON_ITER; i++)
	{
	  numerator = fp32_add (fp32_mult (x_prev, x_prev), fp32_inp);
	  denominator = fp32_mult ((fp_32) 2, fp32_inp);
	  x_curr = fp32_div (numerator, denominator);
	}
    }

  return x_curr;  
}


fp_32 fp32_nat_exp(fp_32 fp32_inp)
{

}



fp_32 fp32_gen_exp(fp_32 fp32_base, fp32_exp)
{

}


fp_32 fp32_nat_log(fp_32 fp32_inp)
{


}


/********** END EXPONENTIAL FUNCTIONS **********/


/********** BEGIN TRIG FUNCTIONS **********/


 /* 
   Trigonometric Functions. Implemented via Taylor Polynomials Currently. 
   Number Of Iterations Set in Parameters Header: should solve instead for 
   max precision possible probably. 
 */
fp_32 fp32_sin(fp_32);
fp_32 fp32_cos(fp_32);
fp_32 fp32_tan(fp_32);

fp_32 fp32_asin(fp_32);
fp_32 fp32_acos(fp_32);
fp_32 fp32_atan(fp_32);

		   
/********** END TRIG FUNCTIONS **********/




/******************* FLOATING POINT HELPER FUNCTIONS ***************/


int extract 
