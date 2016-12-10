//Naive Solution :











//Better Approach:
int numDiv(int n)
{
    int result = 1;   // Initialize result as 1

    for (int p=2; p*p<=n; p++)
    {
        int power = 0;
        while(n%p==0)
        {
          n /= p;
          power++;
        }
        result *= (power+1);
    }

    if (n!=1)    result *= 2 ;

    return result;
}
