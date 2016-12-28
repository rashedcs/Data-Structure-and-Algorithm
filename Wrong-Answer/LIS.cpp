#include <stdio.h>
#include <algorithm>
using namespace std;
int l[1001];
int m[1002][1002];
int N;
int lis(int u, int i){
        if(i == N+1)
                return 0;
		if(m[u][i] != -1)
			return m[u][i];
        if(l[u] < l[i]){
                return m[u][i] = max(lis(i,i+1) + 1, lis(u,i+1));
        }
        return m[u][i] = lis(u,i+1);
}
int main(){
		int T;
		scanf("%d",&T);
		while(T--){
			scanf("%d",&N);
			l[0] = -1;
			for(int i = 0; i < 1002; i++)
				for(int j = 0; j < 1002; j++)
					m[i][j] = -1;
			for(int i = 1; i < N+1; i++){
					scanf("%d",&l[i]);
			}
			printf("%d\n",lis(0,1));
		}
        return 0;
}
