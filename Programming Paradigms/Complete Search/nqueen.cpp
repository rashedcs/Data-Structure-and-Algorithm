#include <bits/stdc++.h>
using namespace std;
 
int n;
int arr[10]; 

int check(int row, int col)
{
    for (int i=0; i<row; i++) 
    {
        if (arr[i] == col || abs(row - i) == abs(col -arr[i]))  return false;
    }
    return true;
}


void print()
{
       cout<<"[";
       for(int row=0; row<n; row++) 
        {
            for(int col=0; col<n; col++) 
            {
                if(arr[row] == col) cout<<col+1<<" ";
            }
        }
        cout<<"] ";
}


 
bool nqueen(int row) 
{
    if (row==n) 
    {
        print();
        return true;
    }
    
    for (int col=0; col<n; col++) 
    {
        if(check(row,col)) 
        {
            arr[row] = col;
            nqueen(row+1);
        }
    }
    return false; 
}
 
 
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
      cin>>n;
      if(n==1)        cout<<"[1 ]";
      else if(n<4)    cout<<"-1";
      else            nqueen(0);
      cout<<endl;
    }
    return 0;
}
 
