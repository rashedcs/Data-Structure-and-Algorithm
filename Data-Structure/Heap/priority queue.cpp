//Source : https://www.quora.com/How-can-I-find-minimum-element-from-a-priority-queue-in-C-C++


/** Without custom comparator class **/
#include <bits/stdc++.h>
using namespace std;
 

int main() 
{
	priority_queue<int, vector<int>, greater<int> > pq;
	
	pq.push(40);
	pq.push(320);
	pq.push(42);
	pq.push(42);
	pq.push(65);
	pq.push(12);
	pq.push(245);
 
	cout<<pq.top()<<endl;
	return 0;
}





/** With custom comparator class **/
#include <bits/stdc++.h>
using namespace std;

struct comp
{
	 bool operator () (int lhs, int rhs)
 	 {
		 return lhs > rhs;
	 }
};

int main(void)
{
  ios::sync_with_stdio(false);
	priority_queue<int, vector<int>, comp> pq;
  
	pq.push(40);
	pq.push(320);
	pq.push(42);
	pq.push(42);
	pq.push(65);
	pq.push(12);
	pq.push(245);

	cout<<pq.top()<<endl;
	return 0;
}
