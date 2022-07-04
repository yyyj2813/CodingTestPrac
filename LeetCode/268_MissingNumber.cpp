class Solution {
public:
    int Sum(int k ){
        return k*(k+1)/2;  
    }
    int missingNumber(vector<int>& nums) {
        int k=Sum(nums.size()); 
        
        for(int n : nums){
            k-=n; 
        }
        return k; 
    }
};