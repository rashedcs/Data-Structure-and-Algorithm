#include<bits/stdc++.h>
  using namespace std;
 
  int arr[90];
  void print (int );
 
 
  bool place(int r, int c)
  {
    for(int i=1; i<=r-1; i++)
     {
       if((arr[i]==c) || abs(i-r)==abs(c-arr[i]))  return false;
     }
     return true;
  }
 

  void nqueen(int row, int n)
  {
     for(int col=1; col<=n; col++)
     {
       if(place(row, col))
        {
           arr[row]=col;
           if(row==n)   print(n);
           else         nqueen(row+1, n);
        }
     }
  }
 

  void print(int n)
  {
    cout<<"[";
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=n; j++)
      {
        if(arr[i]==j)  cout<<j<<" ";
      }
    }
    cout<<"] ";
  }
 
  int main()
  {
    int tc, n;
    cin>>tc;
    while(tc--)
    {
      cin>>n;
      if(n==1)        cout<<"[1 ]";
      else if(n<4)    cout<<"-1";
      else            nqueen(1,n);
      cout<<endl;
    }
    return 0;
  }
 

