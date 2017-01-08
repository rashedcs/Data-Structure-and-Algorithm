#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n,tc, cnt;
    cin>>tc;
    while(tc--)
    {
        cnt = 0;
        cin>>n;
        while(n)
        {
            cnt = cnt + n/5;
            n=n/5;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
 
