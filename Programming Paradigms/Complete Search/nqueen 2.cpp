#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 8
using namespace std;
 
/* print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout<<board[i][j]<<"  ";
        cout<<endl;
    }
}
 
/* check if a queen can be placed on board[row][col]*/
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
 
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }
 
    return true;  
}
 
/*solve N Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
    { 
        printSolution(board);
                return true;
    }
  
    for (int i = 0; i < N; i++)
    {
        if ( isSafe(board, i, col) )
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1) == true)
                return true;
            else board[i][col] = 0;
        }
    }
    return false;
}
 

// Main
int main()
{
       int board[N][N] = {0};
    solveNQUtil(board, 0);
    return 0;
}
 
