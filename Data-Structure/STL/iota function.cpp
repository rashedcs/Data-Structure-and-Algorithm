http://www.geeksforgeeks.org/useful-array-algorithms-in-c-stl/









// C++ code to demonstrate working of iota()
#include<iostream>
#include<numeric> // for iota()
using namespace std;
int main()
{
    // Initializing array with 0 values
    int ar[6] =  {0};
 
    // Using iota() to assign values
    iota(ar, ar+6, 20);
 
    // Displaying the new array
    cout << "The new array after assigning values is : ";
    for (int i=0; i<6 ; i++)
       cout << ar[i] << " ";
 
    return 0;
 
}
