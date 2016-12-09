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


void PF(int n)
{
  for(int i=2; i<=n; i++)
  {
    int cnt = 0;
    if(n%i==0)
    {
      while(n%i==0)
      {
        n = n/i;
      }
      cout<<i<<" ";
    }
  }
}
