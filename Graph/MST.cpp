  #include<bits/stdc++.h>
  using namespace std;

  const int MAX = 1e4 + 5;
  int id[MAX], nodes, edges;
  pair <long long, pair<int, int> > p[MAX];



    // Find the root of the set in which element k belongs
    int Find(int k)
    {
        // if k is root
        if(id[k] == k)
            return k;

        // recurse for parent until we find root
        return Find(id[k]);
    }


    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find root of the sets in which elements
        // x and y belongs
        int x = Find(a);
        int y = Find(b);

        id[x] = y;
    }


 long long kruskal(pair<long long, pair<int, int> > p[], int edges)
 {
    for(int i = 0;i < MAX;++i)  id[i] = i;
    sort(p, p + edges);

    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0; i<edges; ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        // Check if the selected edge is creating a cycle or not
        if(Find(x) != Find(y))
        {
            minimumCost += cost;
            Union(x, y);
        }
    }
    return minimumCost;
 }

 int main()
 {
    ios::sync_with_stdio(false);
    int x, y;
    long long weight, cost, minimumCost;
    //initialize();
    cin>>nodes>>edges;
    for(int i = 0;i < edges;++i)
    {
        cin>>x>>y>>weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order

    minimumCost = kruskal(p,edges);

    cout << minimumCost << endl;
    return 0;
 }



/*
Input :
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Output : 19





/*
void initialize()
{
      for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}



void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];

}




//links : https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
  #include<bits/stdc++.h>
  using namespace std;

  const int MAX = 1e4 + 5;
  int id[MAX], nodes, edges;
  pair <long long, pair<int, int> > p[MAX];



    // Find the root of the set in which element k belongs
    int Find(int k)
    {
        // if k is root
        if(id[k] == k)
            return k;

        // recurse for parent until we find root
        return Find(id[k]);
    }


    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find root of the sets in which elements
        // x and y belongs
        int x = Find(a);
        int y = Find(b);

        id[x] = y;
    }


 long long kruskal(pair<long long, pair<int, int> > p[], int edges)
 {
    for(int i = 0;i < MAX;++i)  id[i] = i;
    sort(p, p + edges);

    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0; i<edges; ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        // Check if the selected edge is creating a cycle or not
        if(Find(x) != Find(y))
        {
            minimumCost += cost;
            Union(x, y);
        }
    }
    return minimumCost;
 }

 int main()
 {
    ios::sync_with_stdio(false);
    int x, y;
    long long weight, cost, minimumCost;
    //initialize();
    cin>>nodes>>edges;
    for(int i = 0;i < edges;++i)
    {
        cin>>x>>y>>weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order

    minimumCost = kruskal(p,edges);

    cout << minimumCost << endl;
    return 0;
 }



/*
Input :
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
Output : 19
/*
void initialize()
{
      for(int i = 0;i < MAX;++i)
        id[i] = i;
}
int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}
*/
































