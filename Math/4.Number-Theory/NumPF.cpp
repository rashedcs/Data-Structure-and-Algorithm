int NumPrimeFactor(int n)
{
    int result = 0;   // Initialize result as n
    for (int p=2; p*p<=n; p++)
    {
        while (n % p == 0)
        {
          n /= p;
          result++;
        }
    }

    if (n!=1)    result -= result / n;

    return result;
}
