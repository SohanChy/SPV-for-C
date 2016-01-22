               
SPV - Sohans Psuedo Vector for C
--------------------------------

> Use C++ STL vectors, in C!  
> Author: Sohan Chowdhury 
> Email:   Sifat3D@gmail.com 
> Website: www.sohan.cf

A struct, malloc and free based attempt to emulate C++ STL vectors in C.
Sohans Psuedo Vector for C or SPV is a struct and a collection of functions in C which allows resizing, inserting, deleting, sorting and much much more.

SPV contains almost every feature of C++ STL vectors, but it does not claim to be as efficient or fast. SPV uses the same concept as C++ vectors, by creating new arrays and copying old arrays to it. The memory consumption and runtime can grow pretty large if the size of the array is significant because SPV does not have the optimizations of STL vectors. But for small programs or projects where C is necessary but memory is not that much of a concern and the data size is not extremely large, SPV can be used as a make shift alternative to C++ vector functionality.

//Using SPV is as simple as typing:

                                    int size = 1;
                                    SPV example;
                                    SPVconstruct( size , &example)

//Thats it!
//Now you can SPV as simply as:

			      example.spv[0] = 5;

//SPVconstruct() MUST be called before using a SPV object, 
//it is recommended to call it right below the declaration.
