
#include<bits/stdc++.h>
using namespace std;

const int MAX = 111111;
vector<int>matrix[MAX];
int inDegree [MAX];



int main ()
{
    ios::sync_with_stdio(false);
    memset(inDegree, 0, sizeof(inDegree));

    int edges, a, b, vertex, cnt=0;
    cin>>vertex>>edges;

    while(edges--)
    {
        cin>>a>>b;
        matrix [a].push_back (b);
        inDegree[b]++;
    }

    queue<int>Q;
    vector<int> sortedList;

    for(int i=1; i<=vertex; i++)
    {
        if(inDegree[i]==0)  Q.push(i);
    }

    while(!Q.empty())
    {
        int u = Q.front ();
        Q.pop ();

        sortedList.push_back(u);

        for(int i=0; i<matrix[u].size(); i++)
        {
            inDegree[matrix [u][i]]--;
            if(inDegree[matrix[u][i]]==0)  Q.push (matrix[u][i]);
        }
        cnt++;
    }

    if(cnt!=vertex) cout<<"Sandro fails.\n";
    else
    {
       for(unsigned int i=0; i<sortedList.size (); i++)
       {
           cout<<sortedList [i]<<" ";
       }
    }


    return 0;
}



//N.B It show error in duplicate elements. we try to use set data structure instead of queue. //using bfs set r8 answer





//Using bfs set : http://ideone.com/hy3TQi
//Using dfs :http://ideone.com/o3lmCn

