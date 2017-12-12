#include<bits/stdc++.h>
using namespace std;


class Solution
{
  public:
     vector<int> twoSum(vector<int> &arr, int target)
     {
        unordered_map<int, int>hash;
        vector<int> result;

        for(int i=0; i<arr.size(); i++)
        {
            int key = target-arr[i];

            if(hash.find(key ) != hash.end())
            {
                result.push_back(hash[key]);
                result.push_back(i);
                return result;
            }
            else
            {
                hash[arr[i]] = i;
            }

        }
        return result;
     }
};

int main()
{
	int input[4] = {3, 2, 4, 3};
	vector<int> nums(input, input + 3);
	int target = 6;

	Solution s;
	vector<int> result = s.twoSum(nums, target);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}
