//LCP
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result=""; 
        if(strs.size()==0) return result;
        result=strs[0];
        for(int i=1; i<strs.size(); i++)
        {
            for(int j=0; j<=min(result.length(), strs[i].length()); j++)
            {
                if(j==strs[i].length())
                {
                result=strs[i]; break; 
                }
                if(result[j]!=strs[i][j])
                {
                  result=result.substr(0, j); break;
                }
            }
        }
        return result; 
    }
};
