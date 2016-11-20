//It is not good for programming contest


#include<bits/stdc++.h>
#define inf 9999
using namespace std;

int main()
{
     int m,n;
     int a,b,c;

    cout << "Enter number of vertex and edjes: ";
    cin >> m >> n;
    vector <int> v[m+1];
    vector <int> cost[m+1];
    int distance[m+1];
    int prev[m+1];
    for(int i=1;i<=m;i++)
    {
        distance[i] = inf;
        prev[i] = -1;
    }

    cout << "Enter a to b cost is c: " << endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        v[a].push_back(b);
        v[b].push_back(a);///Ata na dile shudhu directed ar moto kaz korbe
        cost[a].push_back(c);
        cost[b].push_back(c); ///Ata na dile shudhu directed ar moto kaz korbe
    }
    
    int source,target;
    cout << "Enter source and target and node: ";
    cin >> source >> target;
    queue <int> x;
    distance[source] = 0;
    x.push(source);

    while(!x.empty())
    {
        int u = x.front();
        x.pop();
        for(int i=0;i<v[u].size();i++)
        {
            int p = v[u][i];
            if(distance[u] + cost[u][i] < distance[p])
            {
                distance[p] = distance[u] + cost[u][i];
                x.push(p);
                prev[p] = u;
            }
        }
    }

    int start = target;
    int path[50];
    int j=0;

    while(start!=-1)
    {
        path[j++] = start;
        if(start == source)  break;
        start = prev[start];
    }
    for(int i=j-1;i>=0;i--)
        cout << path[i]<<" -> ";
    cout << endl << "minimum distance: " << distance[target] << endl;
      /*
     
         // For minimum cost of all vertex visit from the source
         for(int i=1; i<=n; i++)
         {
            if(i == source)  continue;
            if(distance[i] >= inf) cout<<"-1"<<" ";
            else cout<<distance[i]<<" ";
         }
         
        cout<<endl;
     
     */
    return 0;
}
