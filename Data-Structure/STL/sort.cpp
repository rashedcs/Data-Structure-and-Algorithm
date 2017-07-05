#include <bits/stdc++.h>
using namespace std;


bool comp(int a, int b)
{
    return a<b;
}



int main()
{
    int arr[] = { 5, 6, 2, 4, 1, 3 };

    sort(arr, arr+6, cmp);

    for (auto item : arr)
    {
        cout<<item<< " ";
    }
    cout<<endl;

    return 0;
}
