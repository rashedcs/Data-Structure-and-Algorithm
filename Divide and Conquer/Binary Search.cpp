#include <iostream>
using namespace std;
 

int BinarySearch(int A[], int low, int high, int x)
{
    if (low > high)
        return -1;
 
    int mid = (low + high)/2;   

    if (x == A[mid])
        return mid;
    else if (x < A[mid])
        return BinarySearch(A, low,  mid - 1, x);
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
