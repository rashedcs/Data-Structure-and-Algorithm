//(a ^ b) % m


//Complexity : O(n)
int mod(int a, int b, int c)
{
    if(b==0) return 1;
    
    if(b%2==0)
    {
        int x=mod(a,b/2,c);
        return (x*x)%c;
    }
    else return (a%c * mod(a,b-1,c))%c;
}



//Complexity : O(log (b))
template <typename T> T power(T e, T n, T m) 
{
 	 T x = 1, p = e;
	 while(n) 
         {
	  	if(n & 1) x = mul(x, p, m);
	  	p = mul(p, p, m);
	  	n >>= 1;
	 }
	 return x;
}
