#include <stdio.h>
#include <stdlib.h>
#include "spv.h"

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
        SPVconstruct() MUST be called before using a SPV object, it is recommended to call it right
	below the declaration.

	The default data type is int, but it can be easily changed by simply editing the spv.h file.

		//Change %d to the appropriate printf format-specifier for your data type of choice.
		#define SPVprintf "%d "
		//Change int to whatever data type you want.
		typedef int SPVtype;

*****************************************************************************************
*/



int main()
{

int arrSize = 5;
int arr[] = {3,2,1,5,4};

//Examples of various SPV functions and uses

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

   return 0;
}

