#include<bits/stdc++.h>
using namespace std;

#define mx 10


 void merge(int arr[], int l, int m,  int h)
 {
    int l1, l2, i;

    l1 = l;
    l2 = m + 1;
    i  = l;
 
    int b[h+1];
  //  int *b = new int [h+l+1];  avabe dile dynamic memory allocation.
    while(l1<=m && l2<=h)
    {
      if(arr[l1]<=arr[l2])
      {
         b[i++] = arr[l1++];
      }

      else
      {
         b[i++] = arr[l2++];
      }
    }

    while(l1<=m)
    {
       b[i++] = arr[l1++];
    }

    while(l2<=h)
    {
       b[i++] = arr[l2++];
    }

    for(i = l; i<=h; i++)
    {
       arr[i] = b[i];
    }
  //delete b;
}


void sortion(int arr[], int low, int high)
{
   int mid;

   if(low < high)
   {
      mid = (low + high) / 2;
      sortion(arr, low, mid);
      sortion(arr, mid+1, high);
      merge(arr, low, mid, high);
   }
}

int main()
{
   int i;
   int arr[mx];

   for(i=0; i<mx; i++)   cin>>arr[i];

   sortion(arr,0, mx-1);

   for(i=0; i<mx; i++)   cout<<arr[i]<<" ";

   return 0;
}

/*
Link 1 : http://code.geeksforgeeks.org/yy6559
Link 2 : https://ideone.com/YkWjYG
*/




