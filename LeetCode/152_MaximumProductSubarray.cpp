class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int min_val=nums[0], max_val=nums[0]; 
        int g_max=max_val; 
        for(int i=1; i<nums.size(); ++i){
            int now = nums[i];
            if(now >= 0) {
                int tmax = max(max_val*now, now);
                int tmin = min(min_val*now, now);
                max_val=tmax;
                min_val=tmin; 
            }
            else if(now<0){
                int tmax =max(min_val*now,now);
                int tmin =min(max_val*now, now);
                max_val=tmax;
                min_val=tmin; 
            }
            g_max=max(g_max, max_val);
        }
        return g_max; 
        
    }
};