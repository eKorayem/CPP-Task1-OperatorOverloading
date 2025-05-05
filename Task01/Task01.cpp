#include <iostream>
#include "MyArray.h"


int main()
{
    int arrSize;
    cout << "Enter array capacity: ";
    cin >> arrSize;
    MyArray A(arrSize);

    A.read_values();

    MyArray B(A);

    cout << "Array B:\n";
    cout << B;
    cout << "-----------------------------------------\n";

    cout << "Element at index A[2] is " << A[2] << endl;

    cout << "-----------------------------------------\n";
    cout << "Set A[2] = 33\n";
    A[2] = 33;
    cout << A;
    cout << "-----------------------------------------\n";


    cout << "Concateate A and B in A\n";
    A = A + B;

    cout << A;

    cout << "-----------------------------------------\n";
    
    cout << "Subtract B from A\n";
    A = A - B;
    cout << "A:\n";
    cout << A;
    cout << "-----------------------------------------\n";

    cout << "Multiply A * 4\n";
    A = A * 4;
    cout << A;


    cout << "-----------------------------------------\n";

    cout << "Expand A size to 15\n";
    A.reallocate(15);
    cout << "Size of A is : " << A.get_size();


    
}
