/*
*****************************************************************************************
                        SPV - Sohans Psuedo Vector for C
                            Use C++ STL vectors, in C!
                            Author: Sohan Chowdhury
                            Email: Sifat3D@gmail.com
                            Website: www.sohan.cf

                        Check README.md for brief instructions.
*****************************************************************************************
*/


#include <stdio.h>
#include <stdlib.h>
#include "spv.h"


int main(void)
{
    int arrSize = 5;
    int arr[] = { 3, 2, 1, 5, 4 };

    //Examples of various SPV functions and uses

    SPV test;

    SPVconstruct(arrSize, &test);
    SPVassign(arr, &test);

    SPVsort(&test, 1);

    SPVprint(&test);

    SPVinsert(&test, 3, 100);
    SPVprint(&test);

    SPVdelete(&test, 3);
    SPVprint(&test);

    SPVpop_front(&test);
    SPVpop_back(&test);

    test.spv[1] = 999;

    SPVprint(&test);

    SPVswap(&test, test.first, test.last);
    SPVprint(&test);

    SPVdestroy(&test);

    return 0;
}

