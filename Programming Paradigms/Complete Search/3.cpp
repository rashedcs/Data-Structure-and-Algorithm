//leetcode : https://leetcode.com/problems/subsets/description/

#include<bits/stdc++.h>
using namespace std;


    
void backtrack(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs)
{
    if(start==nums.size())
    {
        //print one subset per condition;
        return;
    }
    else
    {
        for (int i=start; i<nums.size(); i++) 
        {
            sub.push_back(nums[i]);
            subs.push_back(sub);
            backtrack(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }

}

vector<vector<int> > subsets(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> subs;
	vector<int> sub;  
	subs.push_back(sub);
	backtrack(nums, 0, sub, subs);
	return subs; 
}



int main()
{
    std::vector<int> vec{1,2,3};
    for (const auto &v : subsets(vec)) {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }

}


//https://ideone.com/8EWDAr


