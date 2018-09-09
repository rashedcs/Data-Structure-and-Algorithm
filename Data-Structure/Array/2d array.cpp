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


#include<bits/stdc++.h>
using namespace std;


void solution(int grid[20][20], int r,int c)
{
    	    int row=0,  col=0, tr, tc;

       	    pair<int,int>P[r];
          
            for(int i=0; i<r; i++)
            {
        	   for(int j=0; j<c; j++)
    	    	{
    	   	      	P[i].first += grid[i][j];
    		    	P[i].second += grid[j][i];
    	    	}
            }
          
	    	
    	   	for(int k=0; k<r; k++) 
    		{
    			if(P[k].first%2!=0)
    			{
    			    row++, tr = k+1;
    			}
    			if(P[k].second%2!=0)
    			{
    			    col++, tc = k+1;
    			}
    		}
	    	if(row== 0 && col==0) printf("OK\n");
		    else if(row==1 && col==1) printf("Change bit %d,%d\n", tr, tc);
		    else  printf("Corrupt\n");
			
}
	
	
	
int main() 
{
	
int n;
	while(scanf("%d", &n)==1 && n) 
	{
	    //for 2d array as argument
	    int row=n, col=n;
		int **grid = (int**) malloc(sizeof(int*) * row);
		
        for (int i = 0; i < row; i++)
        {
            *(grid+i) = (int*) malloc(sizeof(int) * col);
        }
        
        //input
		for(int i=0; i<row; i++)
		{
		   	for(int j=0; j<col; j++)
		   	{
		   	    cin>>grid[i][j];
		   	}
		}

		solution(grid,row,col);
		
	}
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
