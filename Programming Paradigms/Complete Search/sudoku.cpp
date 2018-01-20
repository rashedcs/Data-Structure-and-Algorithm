//Sudoku
//Backtracking
#include <bits/stdc++.h>
using namespace std;

int matrix[9][9];

bool findLocation(int &row,int &col)
{
    for(row=0; row<9; row++)
    {
        for(col=0; col<9; col++)
        {
            if(matrix[row][col]==0) return true ;
        }
    }
    return false ;
}

bool usedInRow(int row,int col,int num)
{
    for(int i=0;i<9;i++)
    {
      if(matrix[row][i]==num) return true ;   
    }
    return false ;
}

bool usedInCol(int row,int col,int num)
{
    for(int i=0;i<9;i++)
    {
        if(matrix[i][col]==num) return true ;
    }
    return false ;
}

bool usedInBox(int boxStartRow,int boxStartCol,int num)
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(matrix[boxStartRow+row][boxStartCol+col]==num) return true ;
        }
    }
    return false ;
}

bool isSafe(int row,int col,int num)
{
    if(usedInRow(row,col,num)) return false ;
    else if(usedInCol(row,col,num)) return false ;
    else if(usedInBox(row-row%3,col-col%3,num)) return false ;
    return true ;
}

bool solveSoduko()
{
    int row , col ;
    if(!findLocation(row,col))
    {
           return true ;
    }
    else
    {
        //cout<<row<<" "<<col<<endl;
        for(int num=1;num<=9;num++)
        {
            if(isSafe(row,col,num))
            {
                matrix[row][col]=num;
                if(solveSoduko()) return true ;
                matrix[row][col] = 0 ;
            }
        }
    }
    return false ;
}
void print()
{
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            printf("%d ",matrix[row][col]);
        }
        cout<<endl;
    }
}
int main()
{
           for(int row=0; row<9; row++)
            {
                for(int col=0; col<9; col++)
                {
                    cin>>matrix[row][col];
                }
            }
            if(solveSoduko()) print();


             return 0;
}
