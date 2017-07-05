/** Easiest Way **/

#include<bits/stdc++.h>
using namespace std;
int arr[20][20];

void func(int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
             printf("%d ", arr[i][j]);
        }
        puts(" ");
    }
}



int main( int argc, char* argv[] )
{
  int row, col;
  scanf("%d %d", &row, &col);
  for(int i=0; i<row; i++)
  {
     for(int j=0; j<col; j++)
     {
        scanf("%d", &arr[i][j]);
     }
  }
  func(row, col);
  return 0;
}







/** easy way **/

#include<bits/stdc++.h>
using namespace std;

void doit(int **s , int row, int col)
{
    for (int i=0; i<row; i++)
    {
        for (int j=0 ; j<col; j++)
	{
	     printf("%d ", s[i][j]);	
	}
        printf("\n");
    }
}

int main()
{
    int r = 2, c= 2;
    int** arr = new int*[r];
    for(int i=0; i<r; i++)
    {
      arr[i] = new int[c];
    }
    for(int i=0; i<r; i++)
    {
	for(int j=0; j<c; j++)
	{
	   cin>>arr[i][j];    	
	}     
    }
    doit(arr, r, c);
    return 0;
}





/** complex way **/

 #include<iostream>
 using namespace std;

 template<size_t N, size_t M>
 void print(int (&a)[N][M])
 {
    for(size_t i=0; i<N; i++)
    {
       for(size_t j=0; j<M; j++)
       {
          cout<<a[i][j]<<" ";
       }
       cout<<endl;
    }
 }

int main()
{
   	int a[2][3] = {
   	                 {1,2,3},
	                 {4,5,6},
                     };
         print(a);

}


Daught : http://ideone.com/dLkB42   x not possible
Daught : http://ideone.com/GrGJ52   x not possible
