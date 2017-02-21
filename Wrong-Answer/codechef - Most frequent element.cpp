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
