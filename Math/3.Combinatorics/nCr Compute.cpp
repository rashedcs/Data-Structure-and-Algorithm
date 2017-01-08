///Naive approach

#include<iostream>
using namespace std;
int main()
 {
     int n,r,i;
     long p;
     cin>>n>>r;
     
     p=1;
     for(i=1;i<=r;i++)
      {
         p=p*(n-i+1)/i;
      }
 
     cout<<(long )p;
     return 0;
 }
