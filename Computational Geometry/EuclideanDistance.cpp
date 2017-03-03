http://www.codingalpha.com/calculate-distance-between-two-points-c-program/

#include<bits/stdc++.h>
 using namespace std;



 double dist(pair<int,int> &p,pair<int,int> &q)
 {
    return hypot(p.first-q.first, p.second - q.second);
    //hypot (dx, dy) returns sqrt(dx*dx, dy*dy)
 }


 int main()
 {
	vector<pair<int,int> >V;
	V.push_back(make_pair(4,3));
	V.push_back(make_pair(2,2));

        cout<<dist(V[0], V[1])<<endl;

	return 0;
 }



