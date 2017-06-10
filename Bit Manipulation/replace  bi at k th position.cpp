
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


#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int n,k,t,ans;
	cin>>t;
	while(t--)
	{
	    ans=0;
	    cin>>n>>k;
	    k = floor(log2(n)+1)-k;
        if (n & (1 << (k)) == 0)
            ans = n;
        else
        	ans = n & ~(1 << (k));
    	cout << ans << endl;
	}
	return 0;
}
