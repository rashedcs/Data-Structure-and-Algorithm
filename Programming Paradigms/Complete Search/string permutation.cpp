#include<bits/stdc++.h>
using namespace std;

vector<string>res;

int check(string arr, int m, int n)
{
    if(m!=n && arr[m]==arr[n]) return false;
}

void permute(string arr, int m, int n)
{
     if(m>=n)
     {
         res.push_back(arr);
         return;
     }
     for(int i=m; i<arr.length(); i++)
     {
        if(!check(arr, m, i))
        {
             swap(arr[i], arr[m]);
             permute(arr, m+1, n);
             swap(arr[m], arr[i]); 
        }
     }
}


int main() 
{
    int n, tc;
    string str;
    cin>>tc;
    
    while(tc--)
    {
        res.clear();
        cin>>str;
        n = str.length();
        sort(str.begin(), str.end());
        permute(str, 0 ,n);
        sort(res.begin(),res.end());
        
        for(string iterate:res)
        {
             cout<<iterate<<" ";
        }
        cout<<endl;
    }
	  return 0;
}
