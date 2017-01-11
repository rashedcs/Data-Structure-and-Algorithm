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




//Short Way :
#include<bits/stdc++.h>
using namespace std;




void kmpSearch(string text, string pattern)
{
   ///Calculate Prefix Table
    int n = text.size();
    int m = pattern.size();
    int j = 0;

    int *pre = new int[m];

  	pre[0] = -1;
	pre[1] =  0;

	for (int i=2 ; i<m; i++)
	{
		while (j>0 && pattern[j+1]!=pattern[i])
		{
			j = pre[j];
		}
		if (pattern[i] == pattern[j + 1]) pre[i] = ++j;
		else pre[i] = j;
	}


    ///Now Pattern Matching
    int  k=0;
    for (int i=0; i<n; i++)
    {
        while (k>0 && pattern[k]!=text[i])
        {
           k = pre[k];
        }

        if(pattern[k] == text[i])  k++;

        if (k==m)
        {
            printf("Pattern found at index: %d\n", (i-m)+1);
            k = pre[k];
        }
    }
    free(pre);
}


int main()
{
  string text,pattern;
  cin>>text>>pattern;
  kmpSearch(text,pattern);
  return 0;
}

