https://blog.anudeep2011.com/category/segment-trees/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <map>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define REP(x,y) for (int x=0; x<y; ++x)
 
const int MAXN = 1e5+5;
 
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll> pll;
 
 
int tree[4*MAXN], b[MAXN], a[MAXN], nextt[MAXN];
 
 
void build(int n, int s, int e)
{
    if (s == e)
        tree[n] = s;
    else
    {
        int mid = s+(e-s)/2;
        build(2*n, s, mid);
        build(2*n+1, mid+1, e);
 
        if (b[tree[2*n]] >= b[tree[2*n+1]])
            tree[n] = tree[2*n];
        else
            tree[n] = tree[2*n+1];
    }
}
 
 
int query(int n, int s, int e, int i, int j)
{
     if (s > j || e < i)
        return -1;
 
     if (s >= i && e <= j)
        return tree[n];
 
     int p1, p2, mid = s + (e-s)/2;
     p1 = query(2*n, s, mid, i, j);
     p2 = query(2*n+1, mid+1, e, i, j);
 
     if (p1 == -1)
        return p2;
 
     if (p2 == -1)
        return p1;
 
     if (b[p1] >= b[p2])
        return p1;
     else
        return p2;
}
 
 
int N, M, L, R, k;
 
 
int main()
{
 
    cin>>N>>M;
    for (int i=1; i<=N; ++i)
        scanf("%d", &a[i]);
 
    a[N+1] = -1;
 
    int cnt;
    for (int i=1; i<=N+1; ++i)
    {
        if (i == 1 || a[i] != a[i-1])
        {
            if (i != 1)
                b[i-1] = cnt;
            cnt = 1;
        }
        else
            cnt++;
    }
 
    for (int i=1; i<=N; ++i)
        if (b[i] > 0)
        {
           int j = i;
           nextt[i] = i;
           j--;
           while(j>=1 && b[j] == 0)
            {
                nextt[j] = nextt[j+1];
                j--;
            }
        }
 
    build(1, 1, N);
 
    /*
    for (int i=1; i<=N; ++i)
        cout<<nextt[i]<<" ";
    */
 
    while(M--)
    {
        scanf("%d%d%d", &L, &R, &k);
        //query(1,1,N,L,R);
        int idx = nextt[R];
        //cout<<idx<<" ";
        int val = b[idx];
        int nrb = val - (idx-R);
        if (nrb >= k)
            printf("%d\n", a[idx]);
        else
        {
            idx = nextt[L];
            //cout<<idx;
            if (idx - L + 1 >= k)
                printf("%d\n", a[idx]);
            else
            {
                if (R-1 >= idx)
                {
                    idx = query(1, 1, N, idx+1, R-1);
                    if (b[idx] >= k)
                        printf("%d\n", a[idx]);
                    else
                        printf("-1\n");
                }
                else
                    printf("-1\n");
            }
        }
    }
    return 0;
}
 
/*
7 5
1 1 2 2 2 3 3
1 7 4
*/
 
