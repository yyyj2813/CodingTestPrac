
const int MIN = -987654321;

class Solution {
public:
    int n; 
    vector<vector<int>> cache; 
    
    int GetIdx2(bool robbed, bool first_robbed){
        int ret=0; 
        if(robbed) ret += 2; 
        if(first_robbed) ret+=1;
        return ret; 
    }
    int RobHouses(vector<int>& money, int idx, bool robbed, bool first_robbed){
        
        if(idx == n) return 0;
        
        if(idx==n-1){
            if(first_robbed || !robbed) return 0; 
            else return money[n-1];
        }
        
        int idx2 = GetIdx2(robbed, first_robbed);
        
        int &ret= cache[idx][idx2];
        if(ret!=-1) return ret; 
        
        ret=0;  
        
        int add = robbed?money[idx]:0; 
        ret = add + RobHouses(money, idx+1, false, first_robbed); 
        if(!robbed) ret=max(RobHouses(money, idx+1, true, first_robbed), ret); 
        
        return ret;
    };
    
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1) return nums[0];
        
        cache.assign(n,vector<int>(4,-1));//[idx][robbed*2+ifirst_robbed]
        
        return max(RobHouses(nums, 0, false, false), RobHouses(nums, 0, true, true));
    }
};