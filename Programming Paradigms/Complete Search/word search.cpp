class Solution 
{
    public:

        bool backtrack(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, string &word, int index) 
        {
            if(index==word.size()) return true;
            else if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || visited[row][col] || board[row][col]!=word[index]) return false;
            else 
            {
                visited[row][col] = true;
                if(backtrack(board, visited, row-1, col, word, index+1)) return true;  
                if(backtrack(board, visited, row+1, col, word, index+1)) return true;
                if(backtrack(board, visited, row, col-1, word, index+1)) return true;
                if(backtrack(board, visited, row, col+1, word, index+1)) return true;
                visited[row][col] = false;
            }
            return false;
        }
    
        bool exist(vector<vector<char> > &board, string word) 
        {
            if(board.empty() || board[0].empty()) return false;
            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
            for(int i=0; i<board.size(); i++) 
            {
                for(int j=0; j<board[i].size(); j++) 
                {
                    if(backtrack(board, visited, i, j, word, 0)) return true;
                }
            }
            return false;
        }
};
