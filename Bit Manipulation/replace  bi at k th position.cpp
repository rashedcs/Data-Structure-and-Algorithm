#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n,k;
	    cin>>n>>k;
	    k=floor(log2(n)+1)-k;
	    if(n&1<<k)
	       {
	           n=n^(1<<k);
	           cout<<n<<endl;
	       }
	   else
	   cout<<n<<endl;
	}
	return 0;
}
