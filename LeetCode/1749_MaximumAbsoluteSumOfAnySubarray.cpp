class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_abs_sum=0; 
        int max_sum=0, min_sum=0; 
        for(int num :nums){
            if(num<0){
                min_sum = min_sum+num;
                max_sum=max(max_sum+num, 0);
            }
            else if (num>0){
                max_sum = max_sum+num;
                min_sum=min(min_sum+num, 0);
            }
            max_abs_sum= max({max_abs_sum, max_sum, abs(min_sum)}); 
        }
        return max_abs_sum; 
    }
    
};