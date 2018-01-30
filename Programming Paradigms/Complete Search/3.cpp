//leetcode : https://leetcode.com/problems/subsets/description/
//https://leetcode.com/submissions/detail/137322339/

#include<bits/stdc++.h>
using namespace std;


    
void backtrack(const vector<int>& nums, int len, vector<vector<int>>& res, vector<int>& sub, int begin) 
{
        if (sub.size() == len) 
        {
            res.push_back(sub);
            return;
        }
        //int end = nums.size() - (len - sub.size());
        for (int i=begin; i<=nums.size()-len+sub.size(); i++) 
        {
            sub.push_back(nums[i]);
            backtrack(nums, len, res, sub, i+1);
            sub.pop_back();
        }
}

vector<vector<int>> subsets(vector<int>& nums) 
{
        vector<vector<int>> res(1);
        vector<int> sub;
        for (int i=1; i<=nums.size(); ++i) 
        {
            backtrack(nums, i, res, sub, 0);
        }
        return res;
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


