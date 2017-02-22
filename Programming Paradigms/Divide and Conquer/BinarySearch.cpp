#include <iostream>
using namespace std;
 
// Binary search algorithm to return the position of 
// target x in the sub-array A[low..high] 
int BinarySearch(int A[], int low, int high, int x)
{
    // Base condition (search space is exhausted)
    if (low > high)
        return -1;
 
    // we find the mid value in the search space and 
    // compares it with target value
 
    int mid = (low + high)/2;    // overflow can happen
    // int mid = low + (high - low)/2;
    
    // Base condition (target value is found)
    if (x == A[mid])
        return mid;
    
    // discard all elements in the right search space 
    // including the mid element     
    else if (x < A[mid])
        return BinarySearch(A, low,  mid - 1, x);
    
    // discard all elements in the left search space 
    // including the mid element
    else 
        return BinarySearch(A, mid + 1,  high, x);
}
 
// main function
int main()
{
    int A[] = {2, 5, 6, 8, 9, 10};
    int n = sizeof(A)/sizeof(A[0]);
    int target = 5;
    
    int low = 0, high = n - 1;
    int index = BinarySearch(A, low, high, target);
    
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found in the array";
    
    return 0;
}
/*

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
// main function
int main()
{
    vector<int> arr {1, 2, 5, 8, 9};
    int target = 2;
 
    if (binary_search(arr.begin(), arr.end(), target))
        cout << "Element found ";
    else
        cout << "Element not found in the vector";
        
    return 0;
}


*/
