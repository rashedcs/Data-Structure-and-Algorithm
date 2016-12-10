//Naive Solution 
void primeFactor(int n)
{
  for(int i=2; i<=n; i++)
  {
    //int cnt = 0;
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
