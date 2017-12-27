  #include<bits/stdc++.h>
  using namespace std;
 
  int arr[90];
  void print (int );
 
 
  bool place(int k,int i)
  {
    for(int j=1;j<=k-1;j++)
     {
       if((arr[j]==i)||abs(j-k)==abs(i-arr[j]))  return false;
     }
     return true;
  }
 
 void nqueen(int row, int n)
  {
     for(int i=1;i<=n;i++)
     {
       if(place(row,i))
        {
           arr[row]=i;
           if(row==n)   print(n);
           else         nqueen(row+1,n);
        }
     }
  }
 
  void print(int n)
  {
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=n; j++)
      {
        if(arr[i]==j)  cout<<"Q\t";
        else cout<<"-\t";
      }
      cout<<endl;
    }
    cout<<endl;
  }
 
  int main()
  {
    int n;
    while(cin>>n)
    {
      if(n==1)        cout<<"Q\n";
      else if(n<4)    cout<<"Not Possible\n\n";
      else            nqueen(1,n);
    }
    return 0;
  }
