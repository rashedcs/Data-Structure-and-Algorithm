#include<bits/stdc++.h>
#define ll long long

using namespace std;

int lps(string a, string b)
{
    int n = a.size();
    int arr[n+1][n+1]; 

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0 || j == 0) arr[i][j] = 0;
            else if(a[i-1]==b[j-1]) arr[i][j] = 1 + arr[i-1][j-1];
            else arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
        }
    }
    return arr[n][n];
}


int main()
{
    	int n;

	    string x, y;
	    cin>>x;
	    for(int i=x.size()-1; i>=0; i--)
	    {
	       y += x[i];  
	    }
	    n = x.size();
	    cout<<lps(x, y)<<endl;
	
	return 0;
}
