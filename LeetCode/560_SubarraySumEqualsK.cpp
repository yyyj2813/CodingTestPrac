#include <unordered_map> 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sum_map; 

        int sum=0;
        int cnt=0; 
        
        sum_map[0]=1; 
        
        for(int n: nums){
            sum += n; 
            cnt += sum_map[sum-k]; 
            sum_map[sum]++; 
        }
        
        return cnt; 
    }
};