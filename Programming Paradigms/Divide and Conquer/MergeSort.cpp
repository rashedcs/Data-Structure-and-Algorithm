//Modified Source Code :   http://code.geeksforgeeks.org/yy6559


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





Alternative way :

#include<bits/stdc++.h>
using namespace std;

#define mx 10

int a[mx],b[mx] ;

void sortion(int low, int high)
{
   int i, mid,l1, l2;

   if(low<high)
   {
      mid = (low + high) / 2;
      sortion(low, mid);
      sortion(mid+1, high);

      l1 = low;
      l2 = mid + 1;
      i  = low;

      while(l1<=mid && l2<=high)
      {
        if(a[l1] <= a[l2])
        {
          b[i++] = a[l1++];
        }

        else
        {
          b[i++] = a[l2++];
        }
      }

      while(l1 <= mid)
      {
         b[i++] = a[l1++];
      }

      while(l2<=high)
      {
         b[i++] = a[l2++];
      }

      for(i=low; i<=high; i++)
      {
        a[i] = b[i];
      }
   }
}



// Drive Function
int main()
{

   for(int i=1; i<=mx; i++)   cin>>a[i];

   sortion(1, mx);

   for(int k=1; k<=mx; k++)   cout<<a[k]<<" ";

   return 0;
}








