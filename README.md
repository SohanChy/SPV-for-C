
SPV - Sohans Psuedo Vector for C
--------------------------------

*A port of C++ STL vectors for C*

**S**ohans **P**suedo **V**ector for C or **SPV** is a struct and a collection of functions in C which allows resizing, inserting, deleting, sorting of arrays and much much more.

SPV contains almost every feature of C++ STL vectors, but it does not claim to be as efficient or fast. SPV uses the same concept as C++ vectors, by creating new arrays and copying old arrays to it. The memory consumption and runtime can grow pretty large if the size of the array is significant because SPV does not have the optimizations of STL vectors. But for small programs or projects where C is necessary but memory is not that much of a concern and the data size is not extremely large, SPV can be used as a make shift alternative to C++ vector functionality.


----------


Using SPV is as simple as downloading the [spv.h header file](https://github.com/SohanChy/SPV-for-C/blob/master/spv.h), and copying it to your project directory(where your main.c file is).
And including it by typing in the header:

    #include "spv.h"

Then simply type in main() :

    int size = 1;
    SPV example;
    SPVconstruct( size , &example);

Thats it!
Now you can use SPV as simply as:

    example.spv[0] = 5;

SPVconstruct() MUST be called before using a SPV object,
it is recommended to call it right below the declaration.

The default data type is int, but it can be easily changed by simply editing the spv.h file.

    //Change %d to the appropriate printf format-specifier for your data type of choice.
    #define SPVprintf "%d "
    //Change int to whatever data type you want.
    typedef int SPVtype;


----------
**Functions:**
ALL SPV functions start with the prefix SPV, they must be passed the address of a spv object and other necessary parameters.

**Examples of use of various SPV functions:**

    int arrSize = 5;
    int arr[] = {3,2,1,5,4};

    SPV test;

    SPVconstruct(arrSize,&test);
    SPVassign(arr,&test);

    SPVsort(&test,1);

    SPVprint(&test);

    SPVinsert(&test,3,100);
    SPVprint(&test);

    SPVdelete(&test,3);
    SPVprint(&test);

    SPVpop_front(&test);
    SPVpop_back(&test);

    test.spv[1] = 999;

    SPVprint(&test);

    SPVswap(&test,test.first,test.last);
    SPVprint(&test);

    SPVclear(&test);

Output of the above program should be:

    1 2 3 4 5
    1 2 3 100 4 5
    1 2 3 4 5
    2 999 4
    4 999 2

List of SPV functions:

    void SPVconstruct(int size, SPV* this);  //constructor function, must be called by user before using SPV

    void SPVassign(SPVtype tArr[],SPV* this);    //assigns any passed array to the SPV array.

    void SPVprint(SPV* this);        //Prints the whole array with a newline at end.

    void SPVresize(SPV* this, int change);   //resize array, change can be positive or negative.

    void SPVclear(SPV* this);    //clears and frees all memory

    void SPVdelete(SPV* this, int position); //deletes element at specified position

    void SPVinsert(SPV* this, int position, SPVtype value); //inserts element at specified position

    void SPVswap(SPV* this,int fpos, int spos); //swaps elements of specified positions

    void SPVsort(SPV* this, int order);  //Sorts whole array, ascending if order is >=0, descending if its negative.

    void SPVpush_back(SPV* this, SPVtype value); //Push element to end of array

    void SPVpush_front(SPV* this, SPVtype value);    //Push element to beginning of array

    void SPVpop_front(SPV* this);    //delete first element of array

    void SPVpop_back(SPV* this);     //delete last element of array


----------
## Refactoring with clang-format
> Code Style  WebKit

    https://webkit.org/code-style-guidelines/

### Makefile Has been added for automated build
    > To compile program

        make

    > To clean obj files

        make clean

    > for housekeeping with executables

        make allclean




> SPV for C
> Author: Sohan Chowdhury
> Email:   Sifat3D@gmail.com
> Website: www.sohan.cf




