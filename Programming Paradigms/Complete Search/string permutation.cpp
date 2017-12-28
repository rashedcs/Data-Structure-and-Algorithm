#include<bits/stdc++.h>
using namespace std;

vector<string>res;


void permute(string arr, int m, int n)
{
    if(m>=n)
    {
      res.push_back(arr);
      return;
    }
    for(int i=m; i<arr.length(); i++)
    {
       swap(arr[i], arr[m]);
       permute(arr, m+1, n);
       swap(arr[m], arr[i]); 
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

//Unique permutation : https://ideone.com/QSPney
//Daught : https://ideone.com/QT5eAa
