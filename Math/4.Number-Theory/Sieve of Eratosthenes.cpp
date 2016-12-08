// Sieve of Eratho Source: http://www.geeksforgeeks.org/sieve-of-eratosthenes/
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
