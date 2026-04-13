/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        vector<int>start(n),end(n);

        for(int i=0;i<n;i++){
            start[i]=intervals[i].start,end[i]=intervals[i].end;
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
           int rooms=0,j=0;
        for(int i=0;i<intervals.size();i++){
            if(start[i]<end[j]) rooms++;
            else j++;
        }
        return rooms;
    }
};
