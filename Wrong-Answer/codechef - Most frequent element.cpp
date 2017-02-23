#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
 
const int N_MAX = 1e5;
int N, M;
int A[N_MAX];
vector<int> v;
 
int length(int L, int R, int pos) {//[L, R)
    int i = upper_bound(v.begin(), v.end(), pos)-v.begin();
    return min(R, v[i]) - max(L, v[i-1]);
}
 
int query(int L, int R, int k) {//[L, R)
    if (length(L, R, (L+R)/2) >= k) return A[(L+R)/2];
    return -1;
}
 
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    v.push_back(0);
    for (int i = 1; i < N; i++) {
        if (A[i] != A[i-1]) v.push_back(i);
    }
    v.push_back(N);
    int L, R, k;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &L, &R, &k);
        printf("%d\n", query(L-1, R, k));
    }
 
    return 0;
}



/*

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()
#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define faster_io() ios_base::sync_with_stdio(false)
#define pb push_back
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define TRACE(x) cout << #x << " = " << x << "\n";
#define vii vector<pair<int,int>>

const ll INF = 1000000005;
const ll INFLL = 1000000000000000005ll;
const ll MOD = 1000000007;

// --------------------------------------------------------------------------

const int RIGHT = 131072;
const int SIZE = 265000;

int A[SIZE], L[SIZE], R[SIZE], M[SIZE];
int N, Q;

void build(int n, int a, int b)
{
    if(a == b)
    {
        L[n] = R[n] = M[n] = 1;
        return;
    }

    int mid = (a+b) / 2;
    build(2*n, a, mid);
    build(2*n+1, mid+1, b);

    int sz = (b-a+1) / 2;
    L[n] = L[2*n] == sz && A[mid] == A[mid+1] ? L[2*n] + L[2*n+1] : L[2*n];
    R[n] = R[2*n+1] == sz && A[mid] == A[mid+1] ? R[2*n] + R[2*n+1] : R[2*n+1];
    M[n] = max(max(max(M[2*n], M[2*n+1]), L[n]), R[n]);
    if(A[mid] == A[mid+1]) M[n] = max(M[n], R[2*n] + L[2*n+1]);
}

int query(int l, int r, int n, int a, int b)
{
    if(a > r || b < l) return 0;
    if(a >= l && b <= r) return M[n];

    int mid = (a+b) / 2;
    int ql = query(l, r, 2*n, a, mid);
    int qr = query(l, r, 2*n+1, mid+1, b);

    if(r <= mid) return ql;
    if(l > mid) return qr;

    int at_left = min(mid-l+1, R[2*n]);
    int at_right = min(r-mid, L[2*n+1]);
    int middle = A[mid] == A[mid+1] ? at_left + at_right : 0;
    return max(max(ql,qr), middle);
}

int main()
{
    while(true)
    {
        scanf("%d",&N);
        if(!N) return 0;
        scanf("%d",&Q);
        f(i,1,N) scanf("%d",&A[i]);
        build(1,1,RIGHT);
        while(Q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n", query(l,r,1,1,RIGHT));
        }
    }
}


/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

	int n,m,l,r,k, *arr, *brr;
	cin>>n>>m;
	arr = new int[n];
	brr = new int[n+1];

	brr[0]=0;

	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		brr[i+1] = brr[i] + arr[i];
	}

	while(m--)
	{
		cin>>l>>r>>k;
		int x=-1;
		l--;r--;
		int mid=(l+r)/2;

		for(int i=l; i<=r-k+1; i++)
		{
			if( (brr[i+k]-brr[i])==arr[mid]*k )
			{
				x=arr[mid];
				break;
			}
		}
		cout<<x<<endl;
	}
	free(arr);
	free(brr);

	return 0;
}










/*
#include<bits/stdc++.h>
using namespace std;

const int N_MAX = 1e5;
int N, M;
int A[N_MAX];
vector<int> v;

int length(int L, int R, int pos)
{
    int i = upper_bound(v.begin(), v.end(), pos)-v.begin();
    return min(R, v[i]) - max(L, v[i-1]);
}

int query(int L, int R, int k)
{
    if (length(L, R, (L+R)/2) >= k) return A[(L+R)/2];
    return -1;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    v.push_back(0);
    for (int i = 1; i < N; i++) {
        if (A[i] != A[i-1]) v.push_back(i);
    }
    v.push_back(N);
    int L, R, k;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &L, &R, &k);
        printf("%d\n", query(L-1, R, k));
    }

    return 0;
}






#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int main() { int testCases; std::cin >> testCases;

while(testCases--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n);
    std::vector<std::pair<int, int> > indexMap(n);
    std::set<int> bounds;
    std::vector<long long> ranges(n);

    for (int i=0;i<n;i++) {
        std::cin >> nums[i];
        std::pair<int, int> p(nums[i], i);
        indexMap[i] = p;
    }

    // Sort indexMap.  It will contain all the nums in sorted order,
    // with a map to the original index.
    std::sort(indexMap.begin(), indexMap.end());

    long long numUsed = 0;
    bounds.insert(-1);
    bounds.insert(n);
    for (int i=n-1; i>=0; i--) {
        int index = indexMap[i].second;
        int low   = *(--bounds.lower_bound(index));
        int high  = *(bounds.upper_bound(index));
        long long count = (long long) (index - low) * (high - index);

        bounds.insert(index);
        numUsed += count;
        ranges[n-1-i] = numUsed;
    }

    for (int i=0;i<m;i++)
    {
        long long query;
        int qIndex;
        int result;

        std::cin >> query;
        qIndex = std::lower_bound(ranges.begin(), ranges.end(), query) -
                    ranges.begin();
        result = indexMap[n-1-qIndex].first;
        std::cout << result << std::endl;
    }
}
return 0;
}
*/


