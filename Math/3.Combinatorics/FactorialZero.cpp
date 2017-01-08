//How many zeros in a number factorial
#include<bits/stdc++.h>
using namespace std;


int main()
{
        int n, cnt;

        cnt = 0;
        cin>>n;
        while(n)
        {
            cnt = cnt + n/5;
            n=n/5;
        }
        cout<<cnt<<endl;

       return 0;
}

