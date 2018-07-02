/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


bool cmp(const Interval &A, const Interval &B){
    return A.start<B.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        int n=intervals.size();
        vector<Interval> ans;
        if(!n) return ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int st=intervals[0].start,ed=intervals[0].end;
        for(int i=1;i<n;i++){            
            if(ed>=intervals[i].start){
                ed=max(ed,intervals[i].end);                
            }
            else{                
                ans.push_back(Interval(st,ed));
                st=intervals[i].start;
                ed=intervals[i].end;
            }
        }
        ans.push_back(Interval(st,ed));
        return ans;
    }
};
