/* NEED TO WRITE TEST SUITE FOR THIS GARBAGE TODO TODO TODO
******************************************************************************************



--DO NOT INCLUDE COMPLEX NUMBERS

--ALSO CREATE README DOCUMENTATION

--ALSO NEED TO ADD OVERFLOW DETECTION

--OK so the constants for PI, e, etc...should be hardcoded actually 

*/



/* Contains operations for fixed_point arithmetic. 

   Not can probably re-use this file for other projects.

   This is as recommended in section B.6 of the Pintos Directory

   Notation (given by Pintos documentation): 

   -- x and y are fixed-point numbers

   -- n is an integer

   -- fixed-pointer numbers are in signed p.q format where p+q = 31

   -- Some consequences of 2's compleemnt: 

      1.  SINCE WE ARE USING 2'S COMPLEMENT HERE USING 14 FRAC PRECISION ACTUALLY
          ONLY ALLOWS US A MAX POSITIVE VALUE UP TO (not including, just short) 2^17 = 131072
          WHICH SHOULD ACTUALLY BE JUST FINE FOR OUR PURPOSES, 31 bits is sum NOT 32

      2. Also since 2's complement is being used here, flow detection is NOT an option.
         Both underflow and overflow detection are implemented here. 

   NOTE: Actually...it seems as though 2's complement preserves 
	 even negative numbers under left-shifting unless there
         is overflow. See warning. 

   WARNING: This implementation assumes arithmetic right shifting for the underlying 
            implementation. The C compiler could very well implement logical shifting:
	    nothing is required by any standard (but gcc compiler should be used here)

 */

#include <inttypes.h>

/* Define the desired level of fractional precision...for now we use the example's 14
   fractional bits.  */
#define FRAC_P 14

/* DESIGN NOTES ARE LISTED HERE


   THINK: I want to be able to effortlessly convert between 64 bit fixed point
   and 32 bit. I need to determine how exactly to do this, but I want it to
   simply involve changing a line in the macro-definition top of the file

   EDIT: don't think there is an easy way to do this. for now use 32 bit precision
   since this is what is used in pintos, and should be sufficient for the personal
   instructional purposes I intend. 


   EDIT2: Need to use unsigned. The reason is that overflow for SIGNED integers
   is 

   EDIT3: Also need to use division, since we are using unsigned values now it is unlikely
   shifting will be guaranteed to be arithmetic. 

*/
typedef int32_t fp_32;

inline min(fp x, fp y)
{
  return (x < y) ? x : y;
}

inline max(fp x, fp y)
{
  return (x < y) ? y : x;
}

inline fp int_to_fp(int32_t);
inline int32_t fp_to_int(int32_t);
inline fp add_fp(fp, fp);
inline fp mult_fp(fp, fp);
inline fp div_fp(fp, fp);


inline fp int_to_fp(int32_t n)
{
  return n << FRAC_P;
}

/* For these basic arithmetic routines we do implement overflow and underflow detection, 
   and an error is thrown if these occur--to ensure maximum precision. */


/* This attempts to maximize precision by rounding to the nearest integer. 
   We don't implement the simpler version of always rounding towards 0...for now */
inline int32_t fp_to_int(int32_t x)
{
  if (x >= 0)
    return (x + (1 << (FRAC_P - 1))) >> FRAC_P;

  else 
    return (x - (1 << (FRAC_P - 1))) >> FRAC_P;
}

/* To subtract, multiply values by -1 using the 'mult_fp' functon then add. */
inline fp add_fp(fp x, fp y)
{
  fp 

  
  return x + y;
}

/* The simplest way to implement this is to employ 64-bit integers.
   Even 32 bit machines allow for these extensions, as demonstrated
   by the casting we use. */
inline fp mult_fp(fp x, fp y)
{
  return (fp) ((( (int64_t) x) * y) >> FRAC_P);  
}

inline fp div_fp(fp x, fp y)
{
  return (fp) ((( (int64_t) x) << FRAC_P) / y);
}


inline factorial(size_t n)
{
  size_t product = 1;
  
  while (n > 0)
    {
      product *= n 
      n--;
    }

  return product;
}




/* This will compute exponents using fixed point arithmetic to the desired precision. 
   Remember that fp is a 32 bit representation. For right now we only implement
   with natural base, but the extension should be simple (need to examine its
   numerical stability). */
fp exp_fp(fp x)
{

  /* Use the same method as libfixmath:

     http://en.wikipedia.org/wiki/Exponential_function#Formal_definition

     TO quote the library comments:

     "The algorithm is based on the power series for exp(x)...

      From term n, we get term n+1 by multiplying with x/n"

      Allegedly this also converges much faster on positive values

*/

}


/* Again for now we only have the natural base as an implementation */
fp log_fp(fp x)
{

}

/* */
fp sin_fp(fp x)
{

}


fp cos_fp(fp x)
{

}
