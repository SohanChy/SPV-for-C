#include "spv.h"

void SPVconstruct(int size, SPV* this) //constructor function, zero initializes, must be called by user before using SPV
{
    this->spv = calloc(size, sizeof(SPVtype));
    this->size = size;
    this->first = 0;
    this->last = size - 1;
}

void SPVconstructRaw(int size, SPV* this) //constructor function, DOES NOT INITIALIZE, must be called by user before using SPV
{
    this->spv = malloc(size * (sizeof(SPVtype)));
    this->size = size;
    this->first = 0;
    this->last = size - 1;
}

void SPVassign(SPVtype tArr[], SPV* this) //assigns any passed array to the SPV array.
{
    int i;
    for (i = this->first; i <= this->last; i++) {
        this->spv[i] = tArr[i];
    }
}

void SPVprint(SPV* this) //Prints the whole array with a newline at end.
{
    if (this->size > 0) {
        int i;
        for (i = this->first; i <= this->last; i++) {
            printf(SPVprintf, this->spv[i]);
        }
        printf("\n");
    }
}

void SPVresize(SPV* this, int change) //resize array, change can be positive or negative.
{
    int newSize = this->size + change;

    SPVtype* tmpArr; //take a new tmpArr pointer.

    //This is the main bottleneck of SPV.
    //It works by allocating a new temporary array with bigger/smaller size
    //then it copies old array to the temporary array.
    //after that the old array memory is freed
    //then the old array pointer is reassigned to the temporary ones.
    //Making it the new array.

    tmpArr = calloc(newSize, sizeof(int));

    int limit = 0;
    if (newSize > this->size) {
        limit = this->size;
    }
    else {
        limit = newSize;
    }

    int i;
    for (i = this->first; i < limit; i++) {
        tmpArr[i] = this->spv[i];
    }

    free(this->spv);

    this->spv = tmpArr;
    this->size = newSize;
    this->last = newSize - 1;
}

void SPVclear(SPV* this) //clears and frees all memory
{
    free(this->spv);
    this->size = 0;
    this->last = 0;
}

void SPVdelete(SPV* this, int position) //deletes element at specified position
{
    int iter;
    for (iter = position; iter < this->last; iter++) {
        this->spv[iter] = this->spv[iter + 1];
    }

    SPVresize(this, -1);
}

void SPVinsert(SPV* this, int position, SPVtype value) //inserts element at specified position
{
    SPVresize(this, 1);

    int iter;
    for (iter = this->last; iter > position; iter--) {
        this->spv[iter] = this->spv[iter - 1];
    }

    this->spv[position] = value;
}

void SPVswap(SPV* this, int fpos, int spos) //swaps elements of specified positions
{
    SPVtype tmp;
    tmp = this->spv[fpos];
    this->spv[fpos] = this->spv[spos];
    this->spv[spos] = tmp;
}

//**********************************************************
//Comparison functions for sorting
int SPVcomp_asc(const void* spvE1, const void* spvE2)
{
    int E1 = *((int*)spvE1);
    int E2 = *((int*)spvE2);
    if (E1 > E2)
        return 1;
    if (E1 < E2)
        return -1;
    return 0;
}

int SPVcomp_desc(const void* spvE1, const void* spvE2)
{
    int E1 = *((int*)spvE1);
    int E2 = *((int*)spvE2);
    if (E1 > E2)
        return -1;
    if (E1 < E2)
        return 1;
    return 0;
}
//**********************************************************

void SPVsort(SPV* this, int order) //Sorts whole array, ascending if order is >=0, descending if its negative.
{
    if (order >= 0) {
        qsort(this->spv, this->size, sizeof(SPVtype), SPVcomp_asc);
    }
    else {
        qsort(this->spv, this->size, sizeof(SPVtype), SPVcomp_desc);
    }
}

void SPVpush_back(SPV* this, SPVtype value) //Push element to end of array
{
    SPVinsert(this, this->last + 1, value);
}

void SPVpush_front(SPV* this, SPVtype value) //Push element to beginning of array
{
    SPVinsert(this, this->first, value);
}

void SPVpop_front(SPV* this) //delete first element of array
{
    SPVdelete(this, this->first);
}

void SPVpop_back(SPV* this) //delete last element of array
{
    SPVdelete(this, this->last);
}
