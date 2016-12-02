#include<bits/stdc++.h>
using namespace std;
#define mx 100005

int arr[mx];
int tree[mx*3];

void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }

    else
    {
      int Left=node*2;
      int Right=node*2+1;
      int mid=(b+e)/2;
      build(Left,b,mid);
      build(Right,mid+1,e);

      tree[node] = tree[Left] + tree[Right];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        arr[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}



int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)   return 0;
    if(b>=i&&e<=j) return tree[node];
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;
}




int main()
{
        int t, n, i, j;
        scanf("%d",&n);

        for(int b=0; b<n; b++)   scanf("%d",&arr[b]);

        build(1,1,n);
        //Update(1,1,n,index, value)

        scanf("%d%d",&i,&j);

        printf("%d\n",query(1,1,n,i,j));

       return 0;
}





























/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];


void build()
{  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value)
{  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r)
{  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}


int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 5));
  return 0;
}
*/
