/*
*****************************************************************************************
                          SPV - Sohans Psuedo Vector for C
                            Use C++ STL vectors, in C!
                            Author: Sohan Chowdhury
                            Email: Sifat3D@gmail.com
                            Website: www.sohan.cf


    Sohans Psuedo Vector for C or SPV is a struct and a collection of functions
    in C which allows resizing, inserting, deleting, sorting of arrays and much
    much more.

    SPV contains almost every feature of C++ STL vectors, but it does not claim
    to be as efficient or fast. SPV uses the same concept as C++ vectors, by
    creating new arrays and copying old arrays to it. The memory consumption and
    runtime can grow pretty large if the size of the array is significant because
    SPV does not have the optimizations of STL vectors. But for small programs or
    projects where C is necessary but memory is not that much of a concern and the
    data size is not extremely large, SPV can be used as a make shift alternative
    to C++ vector functionality.

        Using SPV is as simple as typing:
            int size = 1;
            SPV example;
            SPVconstruct( size , &example)

            //Thats it!
            //Now you can SPV as simply as:

            example.spv[0] = 5;

        SPVconstruct() MUST be called before using a SPV object, it is recommended to
        call it right below the declaration.

        The default data type is int, but it can be easily changed by simply editing the spv.h file.
        //Change %d to the appropriate printf format-specifier for your data type of choice.
        #define SPVprintf "%d "
        //Change int to whatever data type you want.
        typedef int SPVtype;

*****************************************************************************************
*/

#ifndef SPV_H_INCLUDED
#define SPV_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
//Change %d to the appropriate printf format-specifier for your data type of choice.
#define SPVprintf "%d "
//Change int to whatever data type you want.
typedef int SPVtype;

//This makes SPV structs behave as SPV objects without mentioning struct every time.
typedef struct SPV SPV;

struct SPV {
    SPVtype* spv;
    int first, last;
    int size;
};

void SPVconstruct(int size, SPV* this); //constructor function, zero initializes, must be called by user before using SPV

//constructor function, DOES NOT INITIALIZE, must be called by user before using SPV
void SPVconstructRaw(int size, SPV* this);

void SPVassign(SPVtype tArr[], SPV* this); //assigns any passed array to the SPV array.

void SPVprint(SPV* this); //Prints the whole array with a newline at end.

void SPVresize(SPV* this, int change); //resize array, change can be positive or negative.

void SPVclear(SPV* this); //clears and frees all memory

void SPVdelete(SPV* this, int position); //deletes element at specified position

void SPVinsert(SPV* this, int position, SPVtype value); //inserts element at specified position

void SPVswap(SPV* this, int fpos, int spos); //swaps elements of specified positions

//Comparison functions for sorting
int SPVcomp_asc(const void* spvE1, const void* spvE2);

int SPVcomp_desc(const void* spvE1, const void* spvE2);

void SPVsort(SPV* this, int order); //Sorts whole array, ascending if order is >=0, descending if its negative.

void SPVpush_front(SPV* this, SPVtype value); //Push element to beginning of array

void SPVpop_front(SPV* this); //delete first element of array

void SPVpop_back(SPV* this); //delete last element of array

// SPV_H_INCLUDED
#endif
