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




















#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int lis( int* a, int N ) {
  int *best, i, j, max = INT_MIN;

  best = (int*) malloc ( sizeof( int ) * N );
  for ( i = 0; i < N; i++ ) best[i] = 1;
 
  // best is an array initialized to all 1s becasue thats the shortest possible answer,
  // which would happen when all numbers in the array are always decreasing. We will use
  // this array to keep track of the best answer for up to each position as we traverse 
  // through the array below.

  // travese from 2nd element till the end
  // this is the right boundary for each iteration
    for ( i = 1; i < N; i++ )

      // traverse from 1st element until i'th element
      for ( j = 0; j < i; j++ )

          // if:
          // a[j] is less than a[i] (number to the left of a[j])
          //     and
          // this increases the best count for that element
          if ( a[i] > a[j] && best[i] < best[j] + 1 )
          {
            // make a record of this
		        best[i] = best[j] + 1;

            // if this best is greater than max, make a record of that
            if(max < best[i])
				      max = best[i];
		      }         
 
    // free
    free( best );

   // return
   return max;
}
// Sample usage.
int main(){
  int b[] = { 1, 3, 2, 4, 3, 5, 4, 6 };
  // the longest increasing subsequence = 13456?
  // the length would be 5, as well lcs(b,8) will return.
  printf("%d\n", lis( b, 8 ) );
}
