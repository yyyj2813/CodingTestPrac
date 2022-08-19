#include <queue> 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; 
        for(int n :nums) pq.push(n);
        
        int x=-1; 
        while(k>0){
            x=pq.top();
            pq.pop(); 
            --k; 
        }
        return x; 
    }
};