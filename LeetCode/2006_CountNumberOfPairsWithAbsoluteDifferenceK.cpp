#include <map> 
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        map<int,int> m;
        for(int n : nums) m[n]++; 
        
        int cnt=0; 
        for(auto it= m.begin(); it!=m.end(); ++it){
            int target= (*it).first+k; 
            auto it2 = m.find(target);
            if(it2 == m.end()) continue; 
            cnt+= (*it2).second*(*it).second; 
        }
        return cnt; 
    }
};