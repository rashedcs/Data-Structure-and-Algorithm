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



       #include<bits/stdc++.h>
        using namespace std;

        class Comp
        {
          public:
            int operator()(int a, int b)
            {
                return a<b;
            }
        };

        int main()
        {
            vector<int>v(10);

            for(int i=0; i<10; i++)
            {
              cin>>v[i];
            }

            sort(v.begin(), v.end(), Comp());

            for(auto item : v)
            {
              cout<<item<<" ";
            }
            cout<<endl;
            return 0;
        }




http://fusharblog.com/3-ways-to-define-comparison-functions-in-cpp/
3 Ways to Define Comparison Functions in C++
    
    1. Define operator<()
    2. Define a custom comparison function
    3. Define operator()()
    
    
