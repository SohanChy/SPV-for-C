#ifndef SPV_H_INCLUDED
#define SPV_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
*****************************************************************************************
                          SPV - Sohans Psuedo Vector for C
		            Use C++ STL vectors, in C!
                            Author: Sohan Chowdhury
                            Email: Sifat3D@gmail.com
                            Website: www.sohan.cf

	Use C++ STL vectors, in C!
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

//Change %d to the appropriate printf format-specifier for your data type of choice.
#define SPVprintf "%d "
//Change int to whatever data type you want.
typedef int SPVtype;

//This makes SPV structs behave as SPV objects without mentioning struct every time.
typedef struct SPV SPV;

struct SPV{
    SPVtype* spv;
    int first,last;
    int size;
};

void SPVconstruct(int size, SPV* this)  //constructor function, zero initializes, must be called by user before using SPV
{
    this->spv = malloc(size*(sizeof(SPVtype)));
    this->size = size;
    this->first = 0;
    this->last = size-1;

    //zero initialization just to be safe.
    int i;
    for(i = this->first; i<=this->last; i++)
    {
        this->spv[i] = 0;
    }
}

void SPVconstructRaw(int size, SPV* this)  //constructor function, DOES NOT INITIALIZE, must be called by user before using SPV
{
    this->spv = malloc(size*(sizeof(SPVtype)));
    this->size = size;
    this->first = 0;
    this->last = size-1;
}

void SPVassign(SPVtype tArr[],SPV* this)    //assigns any passed array to the SPV array.
{
    int i;
    for(i=this->first; i <=this->last; i++)
    {
        this->spv[i] =tArr[i];
    }
}


void SPVprint(SPV* this)        //Prints the whole array with a newline at end.
{
    if(this->size>0)
    {
        int i;
        for(i = this->first; i<=this->last; i++)
        {
            printf(SPVprintf,this->spv[i]);
        }
        printf("\n");
    }
}


void SPVresize(SPV* this, int change)   //resize array, change can be positive or negative.
{
    int newSize = this->size + change;

    SPVtype* tmpArr;    //take a new tmpArr pointer.

    //This is the main bottleneck of SPV.
    //It works by allocating a new temporary array with bigger/smaller size
    //then it copies old array to the temporary array.
    //after that the old array memory is freed
    //then the old array pointer is reassigned to the temporary ones.
    //Making it the new array.

    tmpArr = malloc(newSize*(sizeof(int)));

    int limit=0;
    if(newSize > this->size)
        {
            limit = this->size;
        }
    else
        {
            limit = newSize;
        }

    int i;
    for(i = this->first; i<limit; i++)
    {
        tmpArr[i] = this->spv[i];
    }

    free(this->spv);

    this->spv = tmpArr;
    this->size = newSize;
    this->last = newSize-1;
}

void SPVclear(SPV* this)    //clears and frees all memory
{
    free(this->spv);
    this->size = 0;
    this->last = 0;
}

void SPVdelete(SPV* this, int position) //deletes element at specified position
{
    int iter;
    for(iter=position; iter<this->last; iter++)
    {
        this->spv[iter] = this->spv[iter+1];
    }

    SPVresize(this,-1);
}

void SPVinsert(SPV* this, int position, SPVtype value) //inserts element at specified position
{
    SPVresize(this,1);

    int iter;
    for(iter=this->last; iter>position; iter--)
    {
        this->spv[iter] = this->spv[iter-1];
    }

    this->spv[position] = value;
}

void SPVswap(SPV* this,int fpos, int spos) //swaps elements of specified positions
{
    SPVtype tmp;
    tmp = this->spv[fpos];
    this->spv[fpos] = this->spv[spos];
    this->spv[spos] = tmp;
}

//**********************************************************
//Comparison functions for sorting
int SPVcomp_asc (const void * spvE1, const void * spvE2)
{
    int E1 = *((int*)spvE1);
    int E2 = *((int*)spvE2);
    if (E1 > E2) return  1;
    if (E1 < E2) return -1;
    return 0;
}

int SPVcomp_desc (const void * spvE1, const void * spvE2)
{
    int E1 = *((int*)spvE1);
    int E2 = *((int*)spvE2);
    if (E1 > E2) return  -1;
    if (E1 < E2) return  1;
    return 0;
}
//**********************************************************


void SPVsort(SPV* this, int order)  //Sorts whole array, ascending if order is >=0, descending if its negative.
{
    if(order >=0)
    {
        qsort(this->spv, this->size, sizeof(SPVtype), SPVcomp_asc);
    }
    else
    {
        qsort(this->spv, this->size, sizeof(SPVtype), SPVcomp_desc);
    }

}

void SPVpush_back(SPV* this, SPVtype value) //Push element to end of array
{
    SPVinsert(this,this->last+1,value);
}

void SPVpush_front(SPV* this, SPVtype value)    //Push element to beginning of array
{
    SPVinsert(this,this->first,value);
}

void SPVpop_front(SPV* this)    //delete first element of array
{
    SPVdelete(this,this->first);
}

void SPVpop_back(SPV* this)     //delete last element of array
{
    SPVdelete(this,this->last);
}


#endif // SPV_H_INCLUDED
