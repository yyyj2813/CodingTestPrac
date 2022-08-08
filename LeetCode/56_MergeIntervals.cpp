#include <algorithm> 
#include <stack> 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> st;
        
        for(auto interval: intervals){
            if(!st.empty() && interval[0] <= st.top()[1] ){
                auto top =st.top(); 
                st.pop();
                interval[0]=min(interval[0],top[0]);
                interval[1]=max(interval[1],top[1]);
            }
            st.push(interval);
        }
        
        vector<vector<int>> ans; 
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop(); 
        }
        reverse(ans.begin(), ans.end());
        return ans; 
        
    }
};