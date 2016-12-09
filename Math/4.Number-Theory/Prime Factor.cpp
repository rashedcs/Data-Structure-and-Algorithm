//Unique Prime Factor





//Not unique Prime Factor
void PrimeFact(ll num)
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
