
class Solution {
public:
    int findMin(vector<int>& nums) {
        int b=0; 
        int e=nums.size()-1;
        if(nums[b]<nums[e]) return nums[0];
        if(nums.size()<2) return nums[0];
                    
        int m=0; 
        while(b<e){
            m =(b+e)/2; 
            //cout<<b<<" "<<e<<" "<<nums[m]<<endl;
            if(nums[0]<=nums[m]) b=m+1; 
            else e=m; 
        }
        return nums[e];
    }
};