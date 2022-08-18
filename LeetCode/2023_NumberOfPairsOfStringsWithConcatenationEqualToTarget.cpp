#include <map> 
#include <algorithm> 
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        //sm[key], em[key] 의 idx 끼리 합치면 target이 됨 
        
        map<int, set<int>> sm;// [0~key)까지 일치하는 nums의 idx들 
        for(int i=0; i<nums.size(); ++i){
            auto & now = nums[i]; 
            if(now.size() >= target.size()) continue; 
            
            int tidx = 0; 
            for(; tidx<target.size(); ++tidx){
                if(target[tidx]!=now[tidx]) break; 
            }   
            if(tidx != now.size()) continue;  
            sm[tidx].insert(i); 
        }
        
        map<int, set<int>> em; // [key~target.size())까지 일치하는 nums의 idx들 
        for(int i=0; i<nums.size(); ++i){
            auto & now = nums[i]; 
            if(now.size() >= target.size()) continue;
            
            int eidx = target.size()-1; 
            for(; eidx>=target.size()-now.size(); --eidx){
                if(now[eidx-target.size()+now.size()] != target[eidx]) break; 
            }
            if(eidx!=target.size()-now.size()-1) continue; 
            em[eidx+1].insert(i); 
        }
        
        int cnt=0; 
        for(auto sit= sm.begin(); sit!=sm.end(); ++sit){
            int key = (*sit).first; 
            auto eit= em.find(key); 
            if(eit == em.end()) continue;
            
            auto & s1= (*sit).second; 
            auto & s2= (*eit).second;
            cout<<s1.size()<<" "<<s2.size()<<endl;
            cnt += s1.size() *s2.size(); 
            
            for(auto it= s1.begin(); it!=s1.end(); ++it){
                if( s2.find(*it)!=s2.end() ) cnt -= 1;//자기자신은 제외 
            }
        }
        
        return cnt; 
    }
};