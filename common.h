#ifndef __COMMON__
#define __COMMON__

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>

typedef double DType; /* Double real type for application */

typedef int IntType;    /* Integer type for application */

typedef unsigned int UIntType; /* Unsigned type for application */

#define EQ_EPS 0.000001 // epsilon : presision of arithmetics

#define MAX(a,b)    (a)<(b)?(a):(b)
#define MIN(a,b)    (a)>(b)?(a):(b)

#endif /* __COMMON__ end */
