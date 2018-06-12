/*
Given a collection of intervals, merge all overlapping intervals.
Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
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
    vector<Interval> merge(vector<Interval>& intervals) {
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