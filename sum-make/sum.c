/* 
 * sum.c
 * author: bjr
 * last-update:
 *     28 aug 2025
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sum_util.h"

int main(int argc, char * argv[]) {
    assert(argc==3) ;
    int a = atoi(argv[1]) ;
    int b = atoi(argv[2]) ;
    printf("%d plus %d is %d\n", a, b, sum(a,b)) ;
    return 0 ;
}

