#include <stdio.h>

int main(void)
{
    int num1 = 10, num2 = 24;
    int *pnum1 = &num1, *pnum2 = &num2;     // Declaring pointers
    void swap(int* num1, int* num2);        // Declaring pointer function
    
    printf("%d\n", num1);   // Printing the value stored in num1
    printf("%d\n", num2);   // Printing the value stored in num2   
    printf("%p\n", &num1);  // Printing address of num1
    printf("%p\n", &num2);  // Printing address of num2
    printf("%p\n", pnum1);  // Printing address of num1 using a pointer variable
    printf("%p\n", pnum2);  // Printing address of num2 using a pointer variable
    printf("%d\n", *pnum1); // Printing the value stored in the pointers
    printf("%d\n", *pnum2); // using a dereference operator

    swap(&num1, &num2);     // Passing the addresses of the integer to the
                            // pointer functions
    printf("%d\n", num1);
    printf("%d\n", num2);

    return(0);
}

void swap(int* num1, int* num2) // Using two pointers as arguments
{
    int buffer;
    
    buffer = *num1;     // Dereferencing pointers to access and modify
    *num1 = *num2;      // the values stored at the addresses they
    *num2 = buffer;     // point to.
}

/*
A test file to try using pointers, see how they work.
*/