//0-1 Knaspack 
#include<bits/stdc++.h>
using namespace std;



int knapSack(int wt[], int val[], int n, int W)
{
   int K[n+1][W+1];
   
   for(int i = 0; i <= n; i++)
   {
       for(int w = 0; w <= W; w++)
       {
           if (i==0 || w==0)        K[i][w] = 0;
           else if (wt[i-1] <= w)   K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else                     K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
}


int main()
{
	int tc,n,W,*v,*w;
	cin>>tc;
	while(tc--)
	{
	    cin>>n;

	    cin>>W;

	    v = new int[n];

	    w = new int[n];

	    for(int i=0;i<n;i++)   cin>>v[i];

	    for(int i=0;i<n;i++)   cin>>w[i];

	    cout<<knapSack(w, v, n, W)<<endl;

	}
	return 0;
}
