#include<bits/stdc++.h>
using namespace std;


void doit(int **s , int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0 ;j < col; j++)
            printf("%d ", s[i][j]);
        printf("\n");
    }
}
int main()
{
    int i, j;
    int n = 2, m= 2;

    int** arr = new int*[n];

    for(int i=0; i<n; i++)
    {
      arr[i] = new int[m];
    }



    for (i = 0; i <n; i++)
        for (j = 0; j <m; j++)
            cin>>arr[i][j];

    doit(arr, n, m);
}
