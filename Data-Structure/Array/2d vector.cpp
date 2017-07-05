https://www.quora.com/How-do-I-create-a-2D-vector-array-using-std-vector


#include<bits/stdc++.h>
using namespace std;


void print(const vector <vector<int>> &v, int row, int col)
{
    for(int i=0; i<row;  i++)
    {
       for(int j=0; j<col; j++)
       {
          cout<<v[i][j]<<" ";
       }
       cout<<endl;
    }
}



int main()
{
    ios::sync_with_stdio(false);
    int row, col;
    cin>>row>>col;

    vector <vector<int>> v;
    v.resize(col,vector<int>(row));
    
    //v = {{1,2,3}, {4,5,6}, {7,8,9}};
    
    /** input from use **/
    for(int i=0; i<row; i++)
    {
       for(int j=0; j<col; j++)
       {
          cin>>v[i][j];
       }
    }
    /**      fumction call          **/
    print(v, row, col);
    return 0;
}










#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int row, col;
    cin>>row>>col;

    vector <vector<int>> v;
    v.resize(col,vector<int>(row));

    //v = {{1,2,3}, {4,5,6}, {7,8,9}}; 

    /** input from use **/
    for(int i=0; i<row; i++)
    {
       for(int j=0; j<col; j++)
       {
          cin>>v[i][j];
       }
    }

    for(int i=0;i<row; i++)
    {
       for(int j=0;j<col;j++)
       {
          cout<<v[i][j]<<" ";
       }
    }
    return 0;
}


http://www.geeksforgeeks.org/sorting-2d-vector-in-c-set-1-by-row-and-column/

