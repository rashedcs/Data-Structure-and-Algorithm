//Complexity : 0(nlogn)

#include<bits/stdc++.h>
using namespace std;

int main()
{
   vector<int>v;
   int n, num;
   cin>>n;
   for(int i=0; i<n; i++)
   {
     cin>>num;
     vector<int>::iterator it = lower_bound(v.begin(), v.end(), num);
     if(v.end()==it) v.push_back(num);
     else   v[it-v.begin()] = num;
   }
  cout<<"LIS = "<<v.size()<<endl;


  return 0;
}


