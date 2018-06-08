/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 */
solution 1：
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans=0;
        int n=h.size();
        vector<int> left,right;
        left.assign(n,0);
        right.assign(n,0);
        for(int i=0;i<n;i++)
        {
            left[i]=i;
            while(left[i]>0&&h[i]<=h[left[i]-1])
                left[i]=left[left[i]-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            right[i]=i;
            while(right[i]<n-1&&h[i]<=h[right[i]+1])
                right[i]=right[right[i]+1];
        }
        for(int i=0;i<n;i++)
           ans=max(ans,h[i]*(right[i]-left[i]+1));
        return ans;
    }
};
solution 2：
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans=0;
        int n=h.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()||h[i]>=st.top()) st.push(h[i]);
            else{
                int cnt=0;
                while(!st.empty()&&h[i]<st.top()){
                    cnt++;
                    ans=max(st.top()*cnt,ans);
                    st.pop();
                }
                while(cnt--){
                    st.push(h[i]);
                }
                st.push(h[i]);
            }
        }
        int cc=1;
        while(!st.empty()){
            ans=max(st.top()*cc,ans);
            cc++;
            st.pop();
        }
        return ans;
        
    }
};