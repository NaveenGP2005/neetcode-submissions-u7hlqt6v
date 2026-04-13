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

 bool comp(Interval a,Interval b){
    return a.start<b.start;
 }

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()<=1) return 1;
        sort(intervals.begin(),intervals.end(),comp);
        for(int i=0;i<intervals.size()-1;i++){
              if(intervals[i].end>intervals[i+1].start) return 0;
        }
        return 1;
    }
};
