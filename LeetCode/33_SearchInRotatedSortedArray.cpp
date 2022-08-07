class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int ans=-1; 
        int b=0, e = nums.size()-1, m=0;        
        
        while(b<=e){
            m = b+(e-b)/2;
            // cout<<b<<' '<<m<<' '<<e<<endl;
            
            if(nums[m]==target) return m; 
            else if(nums[b]<=nums[m]){
                if( nums[b]<=target && target<nums[m] ) e = m-1; 
                else b = m+1; 
            }
            else {
                if(nums[m]<target && target<=nums[e]) b = m+1;
                else e=m-1; 
            }
        }
        if(nums[m]==target) return b; 
        return -1;
        
    }
};