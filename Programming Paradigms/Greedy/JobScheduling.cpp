#include<bits/stdc++.h>
using namespace std;


bool comp(const pair <string, pair< int,int> >&a, const pair< string, pair<int, int> >&b)
{
    return a.second.first>b.second.first;
}


void jobScheduling(pair<string, pair<int, int> > P[], int n)
{
    sort(P, P+n, comp);

    int count=0, total=0;

    //cout<<"Job index : "<<"Profit : "<<"Deadline : "<<endl;
    bool slot[n];
    memset(slot,0,sizeof(slot));
    int ans=0;

   /*Job sequencing*/
   for(int i=0;i<n; ++i)
      for(int j=min(n,P[i].second.second)-1; j>=0; --j)   //  for(int j=min(n-1, P[i].second.second-1); j>=0; j--)
      { //we substract from j because array starting with zero not one.........but here n=5 ...so total index = 4
	      
         if(!slot[j])
         {
            slot[j]=true;
            ans += P[i].second.first;
            cout<<P[i].first<<" "<<P[i].second.first<<" "<<P[i].second.second<<endl;
            break;
	 }
      }
     cout<<ans<<"\n";
}


int main()
{
     ios::sync_with_stdio(false);

     int n, profit, dead;
     cin>>n;
	 string job;
     pair <string, pair<int, int > > P[n+1];

     for(int i=0; i<n; i++)
     {
       cin>>job>>profit>>dead;
       P[i] = make_pair(job, make_pair(profit,dead));
     }

     jobScheduling(P,n);

     return 0;
}


 /*
 5
 a 100 2
 b 19 1
 c 27 2
 d 25 1
 e 15 3

 output :
 sort
 a 100 2
 c 27  2
 d 25  1
 b 19  1
 e 15  3



 Select
 a 100 2
 c 27 2
 e 15 3

 tF; 142
 */

///Job Sequencing C++ STL code  link some thng difference below code  :http://ideone.com/nNbTrU 
// Article : https://www.dyclassroom.com/greedy-algorithm/job-sequencing-problem-with-deadline
//Using structure : http://ideone.com/Xfv0rM



//Wrong Logic Code : http://ideone.com/YcLPps      http://ideone.com/Qo9M9a   http://ideone.com/plTe3p
