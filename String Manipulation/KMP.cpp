#include<bits/stdc++.h>
using namespace std;

int pre[10];

int prefix_function(string str)
{
	pre[0] = -1;
	pre[1] =  0;

	int j = 0;

	for (int i=2 ; i<str.size(); i++)
	{
		while (j>0 && str[j+1]!=str[i])
		{
			j = pre[j];
		}
		if (str[i] == str[j + 1]) pre[i] = ++j;
		else pre[i] = j;
	}
//	for(int i=0; i<str.size(); i++) cout<<pre[i]<<" ";
}



void kmpSearch(string text, string pattern)
{

    int n = text.size();
    int m = pattern.size();

    prefix_function(pattern);

    int  i = 0;

    for (int j = 0; j < n; j++)
    {
        while (i > 0 && pattern[i] != text[j])    i = pre[i];

        if (pattern[i] == text[j])
            i++;

        if (i == m)
        {
            printf("Pattern found at index: %d\n", (j-m)+1);
            i = pre[i];
        }
    }
}


int main()
{
  string text,pattern;
  cin>>text>>pattern;
  kmpSearch(text,pattern);
  return 0;
}


