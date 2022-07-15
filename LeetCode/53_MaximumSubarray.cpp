const int MIN = -987654321;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        
        int sum = 0; 
        
        int lbf = 0;
        
        int msum = MIN; 
        
        for(int n: nums){
            sum += n;
            msum = max(msum,(sum-lbf));
            lbf= min(lbf,sum);

        }
        
        
        return msum; 
        
    }
};