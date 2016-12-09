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

Or :
 
void PF(int num)
{
    for (int i=2; i<=num; i++)
    {
         while(num%i == 0)
         {
                num /= i;
                v.push_back(i);
         }
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0; i<v.size(); i++)  cout<<" "<<v[i]<<flush;
    v.clear();
    cout<<endl;
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




 
void PF(int num)
{
    for (int i=2; i<=num; i++)
    {
         while(num%i == 0)
         {
                num /= i;
                v.push_back(i);
         }
    }
    for(int i=0; i<v.size(); i++)  cout<<" "<<v[i]<<flush;
    v.clear();
    cout<<endl;
}

