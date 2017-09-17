# This FILE WILL USE ctypes python module in oprder to perform USE TESTS on the fixed-point
# arithmetic functions

# What I will do is "create" a library, including:
#
#       FP_LIP
#       FP_BLAS
#       FP_LAPACK.
#
# 

from ctypes import *

# On Linux, it is required to specify the filename including the extension to load a library
