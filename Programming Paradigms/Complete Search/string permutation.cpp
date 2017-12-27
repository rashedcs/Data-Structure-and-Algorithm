
#include <bits/stdc++.h>
using namespace std;
 vector<string >v;
void permu(string s,int l,int h)
{
    if(l==h)
        v.push_back(s);
    for(int i=l;i<=h;i++)
    {
        swap(s[i],s[l]);
        permu(s,l+1,h);
        swap(s[i],s[l]);
    }
}
int main()
{
   // cout << "Hello World!" << endl;
  
   string s;
   int i;
   cin>>s;
   permu(s,0,s.size()-1);
   sort(v.begin(),v.end());
   for( i=0;i<v.size();i++)
   {
       if(v[i]!=v[i+1])
            cout<<v[i]<<"\n";
   }
  // if(v[i]!=v[i-1])
    //        cout<<v[i]<<"\n";
    return 0;
}
