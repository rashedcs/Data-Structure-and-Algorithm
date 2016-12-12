//Sieve of Eratosthenes
void sieve(int MAX)
{
    bool *prime = new bool[MAX];      //  http://ideone.com/RUdNpk this link use int instead of bool
    memset(prime, 0, sizeof(prime));  // It is good to use int instead of bool 

    for(int i=2; i*i<=MAX;i++)
    {
        if(prime[i]==0)
        {
           for(int j=2*i; j<=MAX; j+=i)
           {
             if(prime[j]==0)  prime[j]=i;
           }
        }
    }

    for (int p=2; p<=MAX; p++)
    {
        if (!prime[p])
        {
            cout<<p<<" ";
        }
    }
    cout<<endl;

}
























// Sieve of Eratho Source: http://www.geeksforgeeks.org/sieve-of-eratosthenes/
void SieveOfEratosthenes(int n)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n+1];
	memset(prime, false, sizeof(prime));

	for (int p=2; p*p<=n;  p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == false)
		{
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)
				prime[i] = true;
		}
	}

	// Print all prime numbers
	for (int p=2; p<=n; p++)
	if (!prime[p])
		cout << p << " ";
}










void sieve(int num)
{
    long long sum = 0;
    bool prime[num+1];
    memset(prime, true, sizeof(prime));
    
    for (int p = 2; p*p<=num; p++)
    {
        if (prime[p] == true)
        {
            for(int i = p*2; i <= num; i = i + p)
            prime[i] = false;
        }
    }
    
    for (int p = 2; p<=num; p++)
    {
        if (prime[p])
        {
            cout<<p<<" ";
        }
    }
    
    cout<<endl;  
}
