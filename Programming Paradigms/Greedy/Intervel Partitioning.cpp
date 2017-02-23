https://tonycao.gitbooks.io/leetcode-locked/content/LeetCode%20Locked/c1.6.html
http://www.programcreek.com/2014/05/leetcode-meeting-rooms-ii-java/
https://discuss.leetcode.com/topic/20906/java-ac-code-using-comparator
http://www.cnblogs.com/grandyang/p/5244720.html
http://massivealgorithms.blogspot.com/2015/08/like-coding-leetcode-253-meeting-rooms.html
https://discuss.leetcode.com/topic/20971/c-o-n-log-n-584-ms-3-solutions/10
https://github.com/yuanhui-yang/LeetCode-Online-Judge/blob/master/Algorithms/meeting-rooms-ii.cpp

//http://ideone.com/YwoAoL
http://ideone.com/jM6EyU
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector< pair<int,int> > v;
    int noofconf,n,starttime,endtime;
    cin>>noofconf;
    for(int i = 0 ; i < noofconf ; i++)
    {
        cin>>starttime>>endtime;
        v.push_back(make_pair(starttime,endtime));
    }
    sort(v.begin(),v.end());

    int noofrooms=0;
    for(int i = 0 ; i < noofconf ; i++)
    {
        if(v[i].second > v[i+1].first)
            noofrooms++;
    }
    cout<<noofrooms;

    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution
{
public:
int minMeetingRooms(vector<Interval>& intervals)
{
   vector<pair<int, int>> changes;
    for (auto i : intervals) {
        changes.push_back({i.start, 1});
        changes.push_back({i.end, -1});
    };
       sort(begin(changes), end(changes));
    int rooms = 0, maxrooms = 0;
    
  
    for(int i=0; i<3; i++)
       // maxrooms = max(maxrooms, rooms += change.second);
       maxrooms = max(maxrooms, rooms += changes[i].second);
    return maxrooms;
}

};
 
int main() {
	Solution solution;
	vector<Interval> intervals = {{0, 30}, {5, 10}, {15, 20}};
	cout << solution.minMeetingRooms(intervals) << "\tPassed\n";
	intervals.clear();
	//cout << solution.minMeetingRooms(intervals) << "\tPassed\n";
	intervals = {{9, 10}, {4, 9}, {4, 17}};
	cout << solution.minMeetingRooms(intervals) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}


// greedy : always change the smallest end time;
// heap : min_heap
// sort : sort the intervals by start time O(nlogn)
int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](Interval &i, Interval &j){return i.start < j.start;});
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(auto interval : intervals){
        if(!min_heap.empty() && min_heap.top() <= interval.start) min_heap.pop();
        min_heap.push(interval.end);
    }
    return min_heap.size();
}
