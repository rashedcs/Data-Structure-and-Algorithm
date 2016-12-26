


//(a ^ b) % m
//Complexity : O(log (b))
template <typename T>T power(T e, T n, T m) 
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
