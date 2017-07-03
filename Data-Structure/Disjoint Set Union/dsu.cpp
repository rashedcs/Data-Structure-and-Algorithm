// Union Find Disjoint
// Also called Disjoint Set Union (DSU) .
// Two heuristics are used , called "union by rank" and "path compression" .
#include <stdio.h>
using namespace std;
int parent[1000];
int rank[1000];
int find_parent(int x) // path compression
{
    if(parent[x]==x) return x;
    else return parent[x] = find_parent(parent[x]);
}
void Union(int a,int b) // union by rank
{
    int x = find_parent(a) , y = find_parent(b);
    if(x==y) printf("THEY ARE ALREADY FRIENDS\n");
    else
    {
        if(rank[x]>rank[y]) parent[y] = x ;
        else parent[x] = y ;
        if(rank[x]==rank[y]) rank[y]++;
    }
}
void makeset(int N)
{
    for(int i=1;i<=N;i++) parent[i] = i , rank[i] = 0 ;
}
int main()
{
    int N,M; // N is the number of persons M is the number of friends
    scanf("%d%d",&N,&M);
    makeset(N);
    while(M--)
    {
        int a , b ;
        scanf("%d%d",&a,&b);
        Union(a,b);
    }
    return 0;
}
