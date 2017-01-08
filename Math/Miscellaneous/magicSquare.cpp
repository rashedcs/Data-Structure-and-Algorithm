#include<bits/stdc++.h>
using namespace std;

void magic(int n)
{

    int k,l;
    int a[10][10];

    memset(a,0,sizeof(a));

    if(n%2 == 0)
    {
        cout << "n is even not possible magic matrix" << endl;
        return;
    }

    else
    {
        a[0][n/2]=1;
        int row = 0;
        int col = n/2;

        for(int key=2;key<=n*n;key++)
        {
            (row>=1)?  k = row-1: k = n-1;

            (col>=1)?  l = col-1: l = n-1;

            if(a[k][l]==0) //If array is empty
            {
                row = k;
                col = l;
                a[row][col] = key;
            }

            else
            {
                 row = (row+1)%n;
                 col = (col/1)*1; //col = col col no change
                 a[row][col] = key;
            }
         }
    }

    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter size matix size: ";
    cin >> n;
    magic(n);
    return 0;
}
