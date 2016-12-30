//Magic Square 
#include<bits/stdc++.h>
using namespace std;


void magic(int n)
{
    int row, col, memo[n][n];
    memset(memo, 0, sizeof(memo)); //Initialize memo to zero

    row = 0;
    col = (n-1)/2;

    memo[row][col]=1; //Middle of the first row


    for(int key=2; key<=n*n; key++)
    {
      (row)?  row=row-1 : row=n-1;

      (col)?  col=col-1 : col=n-1;

      ///Check cell is empty or not
      if(memo[row][col]==0)
      {
         row = row;
         memo[row][col]=key;
      }
      else
      {
        row = (row+1)%n;
        memo[row][col]=key;
      }

    }

   ///Print the magic Square
    for(int i=0; i<n; i++)
    {
      for(int k=0; k<n; k++)
      {
        cout<<memo[i][k]<<" ";
      }
      cout<<endl;
    }
}

//Drive function
int main()
{
  int n;
  cin>>n;
  magic(n);
  return 0;
}

//http://ideone.com/AfTtgz
