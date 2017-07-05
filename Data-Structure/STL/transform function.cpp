#include <bits/stdc++.h>
using namespace std;


int calculation(int x)
{
   return x*x;
}

int main()
{

    int arr[] = { 5, 6, 2, 4, 1, 3 };

    transform (arr, arr+6, arr, calculation);
    copy(arr, arr+6, ostream_iterator<int>(cout," "));

    cout<<endl;

    for_each(arr, arr+6, calculation);
     for(auto n: arr) 
     {
       cout << n << ", ";
     }
     
    return 0;
}
