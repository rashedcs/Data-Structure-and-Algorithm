#include <bits/stdc++.h>
using namespace std;

/*
bool comp(int a, int b)
{
    return a<b;
}
*/

int main()
{
    int arr[] = { 5, 6, 2, 4, 1, 3 };

    //sort(arr, arr+6, cmp);
    //sort(arr, arr+n, greater<int>());
    //sort(arr, arr+n, less<int>());
   
    /* Acsending order */
    sort(arr, arr+n);
    
    for (auto item : arr)
    {
        cout<<item<< " ";
    }
   
    /* Descending order */   
    sort(arr, arr+n);
    reverse(arr, ar+n);
        
    for (auto item : arr)
    {
        cout<<item<< " ";
    }
    cout<<endl;

    return 0;
}
