      /*  1st way :  */

        #include<bits/stdc++.h>
        using namespace std;


	int main(int argc, char const *argv[])
	{
		int n, t, data, key;
		map<int,int> mp;

		cin>>n;
		for (int i=0; i<n; i++)
		{
		    cin>>data>>key;
		    mp[data] = key;
		}

		for(auto val : mp )
		{
		   int key = val.first;
		   int value = val.second; ///data occurence
		   cout<<key<<" "<<value<<endl;
		}
		return 0;
	}







        /* Convert map to vector of pair */

	#include<bits/stdc++.h>
	using namespace std;

	/*
	bool cmp(const pair<int, int>  &p1, const pair<int, int> &p2)
	{
	    return p1.second < p2.second;
	}
	*/

	int main()
	{
	    ios::sync_with_stdio(false);

	    map<int, int>m;

	    for(int i=0; i<10; i++)
	    {
	       m[i] = 5*i;
	    }
		
	    vector<pair<int, int> > v(m.begin(), m.end());
		
	    /*
		vector<pair<int, int> > v;
		copy(m.begin(), m.end(), back_inserter(v));
		sort(v.begin(), v.end(), cmp);
	    */
	    for(int i=0; i<v.size(); i++)
	    {
		cout<<v[i].first<< " : " <<v[i].second<<endl;
	    }
	    return 0;
	}






	/** copy map key to vector:  **/
	map<int, int>m;
	vector<int>keys;
	transform( m.begin(), m.end(), back_inserter(keys), [](std::pair<int, int> p) { return p.first;} );



	/** copy map value to vector:  **/
	map<int, int>m;
	vector<int>keys;
	transform( m.begin(), m.end(), back_inserter(keys), [](std::pair<int, int> p) { return p.second;} );









      
    /* Find the frequency of array of element */
        #include <bits/stdc++.h>
	using namespace std;



	int main(int argc, char const *argv[])
	{
	        int n, t, maxn;
	        map<int,int> mp;
	
	        cin>>n;
		for (int i=0; i<n; i++)
		{
			cin>>t;
			mp[t]++;  //Increasing particular index like : 1 2 2 3 then map : 1:1 ; 2:3
		}

	       for(auto val : mp )
	       {
		  int key = val.first;
		  int value = val.second; ///occurence / value
		  cout<<key<<" "<<value<<endl;
	       }

	       for( auto it = my_map.begin(); it != my_map.end(); ++it )
	       {
	          int key = it->first;
	          string& value = it->second;
	       }

	      return 0;
	}



