//Euler's Totient Function : http://www.geeksforgeeks.org/eulers-totient-function/

// Naive Algorithm: 
// A simple method to evaluate Euler Totient Function
int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i=2; i<n; i++)
    {
        if (__gcd(i, n) == 1)  result++;
    }
    return result;
}


// Euler's product formula Algorithm :
// Euler's product formula to evaluate Euler Totient Function
int phi(int n)
{
    int result = n;   // Initialize result as n
    for (int p=2; p*p<=n; p++)
    {
        if (n % p == 0)
        {
          result -= result / p;
        }
        
        while (n % p == 0)
        {
          n /= p;
        }
    }

    if (n > 1)    result -= result / n;
    
    return result;
}
