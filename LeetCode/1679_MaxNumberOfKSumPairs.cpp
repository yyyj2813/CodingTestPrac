#include <map> 
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m; 
        for(int num : nums)m[num]++; 
        
        int cnt = 0; 
        
        for(auto it = m.begin(); it!=m.end(); ++it){
            int target = k-(*it).first;
                
            if(target < (*it).first) continue; 
            
            auto tit= m.find(target);
            //한 번만 pair를 찾기 때문에 update 해주지 않아도 됨
            if(tit==it) cnt += (*it).second/2; 
            else cnt +=  min((*tit).second, (*it).second);
        }
        
        return cnt; 
    }
};