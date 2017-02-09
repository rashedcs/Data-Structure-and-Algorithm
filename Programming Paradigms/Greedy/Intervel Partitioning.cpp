https://tonycao.gitbooks.io/leetcode-locked/content/LeetCode%20Locked/c1.6.html
http://www.programcreek.com/2014/05/leetcode-meeting-rooms-ii-java/
https://discuss.leetcode.com/topic/20906/java-ac-code-using-comparator
http://www.cnblogs.com/grandyang/p/5244720.html
http://massivealgorithms.blogspot.com/2015/08/like-coding-leetcode-253-meeting-rooms.html
    public int minMeetingRooms(Interval[] intervals) {
        int[] starts = new int[intervals.length];
        int[] ends = new int[intervals.length];
        for(int i=0; i<intervals.length; i++) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }
        Arrays.sort(starts);
        Arrays.sort(ends);
        int rooms = 0;
        int endsItr = 0;
        for(int i=0; i<starts.length; i++) {
            if(starts[i]<ends[endsItr])
                rooms++;
            else
                endsItr++;
        }
        return rooms;
    }
