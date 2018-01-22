//leetcode : https://leetcode.com/problems/subsets/description/
//https://ideone.com/8EWDAr
	#include<bits/stdc++.h>
        using namespace std;


	void print(vector<int>out)
	{

	 for(int i: out)
	   cout<<i<<" ";
	  cout<<endl;
	}



	void findpowerSet(int S[], vector<int>&out, int i)
	{
		 if(i<0)
		 {
		   print(out);
		   return ;
		 }
		 
		 out.push_back(S[i]);
		 findpowerSet(S, out, i-1);
		 out.pop_back();
		 while(S[i]==S[i-1])
		   i--;

		findpowerSet(S, out, i-1);
	}


	int main()
	{

		int S[] = {1, 3, 1};
		int n = 3;
		sort(S, S+n);
		vector<int>out;
		findpowerSet(S, out, n-1);
		return 0;
	}




