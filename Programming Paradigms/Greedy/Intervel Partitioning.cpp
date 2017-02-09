https://tonycao.gitbooks.io/leetcode-locked/content/LeetCode%20Locked/c1.6.html
http://www.programcreek.com/2014/05/leetcode-meeting-rooms-ii-java/
https://discuss.leetcode.com/topic/20906/java-ac-code-using-comparator
http://www.cnblogs.com/grandyang/p/5244720.html
http://massivealgorithms.blogspot.com/2015/08/like-coding-leetcode-253-meeting-rooms.html
 

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        int res = 0, endpos = 0;
        for (auto a : intervals) {
            starts.push_back(a.start);
            ends.push_back(a.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0; i < intervals.size(); ++i) {
            if (starts[i] < ends[endpos]) ++res;
            else ++endpos;
        }
        return res;
    }
};
