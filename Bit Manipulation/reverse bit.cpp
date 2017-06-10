//Reverse a 32 bit given number.
#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);

	int  n, bit;
	unsigned int rev;

	        bit = 32;
	        cin>>n;
		rev=0;
	
		for(int i=0; i<bit; i++)
		{
		    rev<<=1;
		    rev |= (n&1); // // if(n&1)  rev|=1;
		    n>>=1;
		}
	
	cout<<rev<<endl;
	return 0;
}



//Reverse the binary number 
http://algorithms.tutorialhorizon.com/reverse-the-binary-representation-of-a-number/
