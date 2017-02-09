https://tonycao.gitbooks.io/leetcode-locked/content/LeetCode%20Locked/c1.6.html
http://www.programcreek.com/2014/05/leetcode-meeting-rooms-ii-java/
https://discuss.leetcode.com/topic/20906/java-ac-code-using-comparator
http://www.cnblogs.com/grandyang/p/5244720.html
http://massivealgorithms.blogspot.com/2015/08/like-coding-leetcode-253-meeting-rooms.html
    https://discuss.leetcode.com/topic/20971/c-o-n-log-n-584-ms-3-solutions/10
https://github.com/yuanhui-yang/LeetCode-Online-Judge/blob/master/Algorithms/meeting-rooms-ii.cpp




int minMeetingRooms(vector<Interval>& intervals) {
    vector<pair<int, int>> changes;
    for (auto i : intervals) {
        changes.push_back({i.start, 1});
        changes.push_back({i.end, -1});
    };
    sort(begin(changes), end(changes));
    int rooms = 0, maxrooms = 0;
    for (auto change : changes)
        maxrooms = max(maxrooms, rooms += change.second);
    return maxrooms;
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
