#include<bits/stdc++.h>
using namespace std;


bool issafe(int x,int y,int N,int M)
{
    return (x>=0 && y>=0 && x<N && y<M);
}



void floodfill(int **arr,bool **visited,int n,int m, int newColor, int x, int y, int colour)
{
    if(!issafe(x,y,n,m) || arr[x][y]!=colour)  return;
    else
    {
        arr[x][y] = newColor;
        floodfill(arr,visited,n,m,newColor,x,y+1,colour);
        floodfill(arr,visited,n,m,newColor,x+1,y,colour);
        floodfill(arr,visited,n,m,newColor,x,y-1,colour);
        floodfill(arr,visited,n,m,newColor,x-1,y,colour);
    }
}
int main()
{
    	int  n, m, x, y, k, oldColor;
    	cin>>n>>m;
      
      int **arr = new int*[n];
      bool **visited = new bool*[n];
    
    	for(int i=0;i<n;i++)
    	{
    		  arr[i] = new int[m];
    	  	visited[i] = new bool[m];
          for(int j=0;j<m;j++)
          {
            cin>>arr[i][j];
          }
    	}
    	cin>>x>>y>>k; //k is  new color/replacement color 
      
      oldColor = arr[x][y];
    	floodfill(arr,visited,n, m, k, x, y, oldColor); // nxm matrix
    
    	for(int i=0;i<n;i++)
    	{
          for(int j=0;j<m;j++)
          {
              cout<<arr[i][j]<<" "; 
          }
    	}
    	cout<<endl;

	    return 0;
}
