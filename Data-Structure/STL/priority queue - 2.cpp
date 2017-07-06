#include<bits/stdc++.h>
using namespace std;

struct man
{
  string name;
  int priority; 
};

class comparator
{
 public:
   bool operator()(const man& a, const man& b)
   {
        return a.priority<b.priority;
   }
};

int main()
{
   man arr[3];
   priority_queue<man, vector<man>, comparator> pq;

   for(int i=0; i<3; i++)
   {
     cin>>arr[i].name>>arr[i].priority;
     pq.push(arr[i]);
   }
   
   while (!pq.empty())
   {
     cout<<pq.top().name<<" "<<pq.top().priority;
     pq.pop();
     cout<<endl;
   }
   return 0;
}
