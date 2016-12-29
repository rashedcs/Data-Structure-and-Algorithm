 * http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

// Longest Palindromic Subsequence - Dynamic Programming

#include <iostream>
#include <algorithm>

using namespace std;

int lps(string & s, int size_s)
{
	int mat[size_s][size_s];

	// strings de tamanho 1 são palíndromos de tamanho 1
	for(int i = 0; i < size_s; i++)
		mat[i][i] = 1;

	int tam = 2;

	while(tam <= size_s)
	{
		for(int i = 0, j = tam - 1 + i; j < size_s; i++, j++)
		{
			if(s[i] == s[j] && tam == 2)
				mat[i][j] = 2;
			else if(s[i] != s[j])
				mat[i][j] = max(mat[i][j - 1], mat[i + 1][j]);
			else
				mat[i][j] = mat[i + 1][j - 1] + 2;
		}
		tam++;
	}

	return mat[0][size_s - 1];
}

int main(int argc, char *argv[])
{
	string s("ATCATA");

	cout << lps(s, s.size()) << endl;

	return 0;
}











// Longest Palindromic Subsequence Dynamic Problem
Source : copied
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define memo(a,b) memset(a,b,sizeof(a))
char arr[1000];
int dp[1000][1000];
int solve(int low,int high)
{
    if(low>high) return 0;
    if(low==high) return 1;
    int &ret = dp[low][high];
    if(arr[low]==arr[high]) return ret = 2 + solve(low+1,high-1);
    else return ret = max(solve(low+1,high),solve(low,high+1));
}
int main()
{
    scanf("%s",&arr);
    memo(dp,-1);
    cout<<solve(0,strlen(arr)-1)<<endl;
    return 0;
}
