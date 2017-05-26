#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
typedef pair<int,int> pi;
char grid[1001][1001];
long long dp[1001][1001];
int n;
bool vis[1001][1001];
long long M=(2LL<<30LL)-1;
bool ingrid(int a,int b){
	return a>=0 && a<n && b>=0 && b<n;
}
bool dfs(int i){
	stack<pi> stk;
	stk.push(make_pair(0,0));
	vis[0][0]=1;
	int rw[4]={0,-1,0,1};
	int cl[4]={-1,0,1,0};
	while(!stk.empty()){
		pi tmp=stk.top();
		stk.pop();
		if(tmp.first==n-1 && tmp.second==n-1)
			return 1;
		for(int i=0;i<4;i++){
			int x=tmp.first+rw[i];
			int y=tmp.second+cl[i];
			if(ingrid(x,y) && !vis[x][y] && grid[x][y]!='#'){
				vis[x][y]=1;
				stk.push(pi(x,y));
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",grid[i]);
	for(int i=0;i<n;i++){
		if(grid[0][i]=='.')
			dp[0][i]=1;
		else
			break;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]=='.' && dp[i-1][j]!=0){
				dp[i][j]+=dp[i-1][j];
				dp[i][j]%=M;
			}
			if(j>0 && grid[i][j]=='.' && dp[i][j-1]!=0){
				dp[i][j]+=dp[i][j-1];
				dp[i][j]%=M;
			}
		}
	}
	memset(vis,0,sizeof vis);
	if(dp[n-1][n-1]!=0)
		printf("%lld\n",dp[n-1][n-1]);
	else if(dfs(0))
		printf("THE GAME IS A LIE\n");
	else
		printf("INCONCEIVABLE\n");
	return 0;
}
