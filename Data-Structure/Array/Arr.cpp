#include<bits/stdc++.h>
using namespace std;



int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0; i<n;i++)
   {
     cin>>arr[i];
   }

   for(auto key : arr)
   {
      cout<<key<<" ";
   }

   return 0;
}



/** Convert array to vector **/
int arr[3] = {1, 2, 3};
int n = sizeof x / sizeof x[0]; //array size 
   below two way:
     1.  vector<int> v(arr, arr+n);  
     2.  vector<int> v;   v.assign(arr, arr+n);



/**Conver vector to array **/
  vector<int>v = {7, 8, 9, 10, 11};
  int *arr = v.data();

     svector<int> v;
     int* a = &v[0];









