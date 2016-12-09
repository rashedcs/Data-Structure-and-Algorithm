//Unique Prime Factor
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
         cnt++;
       }
       cout<<i<<" ";
    }
  }
}




//Not unique Prime Factor
void PF(ll num)
{
    cout<<"1";
    for (ll i=2; i<=num; i++)
    {
         while(num%i == 0)
         {
                num /= i;
               cout<<i<<" ";
         }
    }
    cout<<endl;
 
}
