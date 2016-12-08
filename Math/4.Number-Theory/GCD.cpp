//Find gcd of 2 numbers a, b
//Complexity: O(log(max(a, b)))

int gcd(int a, int b)
{
 if(a%b==0) return b;
 else       return gcd(b, a%b);
}


// Using Templete
template<typename T> T gcd(T a, T b) 
{
	return (b ? __gcd(a,b): a);
}
