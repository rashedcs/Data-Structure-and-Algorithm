 #include<bits/stdc++.h>
 using namespace std;



 bool compare(pair<int,int> &p,pair<int,int> &q)
 {
    if(p.first==q.first && p.first==q.first ) return true;
    else                                      return false;
 }


 int main()
 {
	vector<pair<int,int> >V;
	V.push_back(make_pair(2,2));
	V.push_back(make_pair(2,2));

    cout<<compare(V[0], V[1])<<endl;

	return 0;
 }



