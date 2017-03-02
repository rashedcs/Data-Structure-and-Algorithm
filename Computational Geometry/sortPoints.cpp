#include<bits/stdc++.h>
using namespace std;


/*
 bool compare(pair<int,int> &p,pair<int,int> &q)
 {
	return p.first < q.first;
 }
*/

 int main()
 {
	vector<pair<int,int> >V;

	V.push_back(make_pair(2,2));
	V.push_back(make_pair(4,3));
	V.push_back(make_pair(2,6));
	V.push_back(make_pair(6,6));
	V.push_back(make_pair(2,4));


	sort(V.begin(),V.end());

	for(int i=0; i<V.size(); i++)
	    cout<<V[i].first<<" "<<V[i].second<<endl;
	return 0;
 }
