#ifndef __HELPERS__H__
#define __HELPERS__H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FALSE 0
#define TRUE 1
#define MATRIX_NOT_DEFINED -1
#define LL_EMPTY -1
#define QUEUE_EMPTY -1
#define MATRIX_DIMENSIONS_INCORRECT -2

#define TElement int



// returns value of smaller number
TElement min(TElement x, TElement y);

// returns value of the greater number
TElement max(TElement x, TElement y);

#endif