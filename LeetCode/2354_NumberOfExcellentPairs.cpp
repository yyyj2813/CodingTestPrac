#include <set> 
#include <map> 
class Solution {
public:
    int CntSetBits(unsigned int n ){
        if(n == 0) return 0; 
        return n%2 + CntSetBits(n/2); 
    }
    
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> s; 
        map<int, int> m;
        
        for(int num : nums) {
            if(s.find(num)!= s.end()) continue; 
            s.insert(num);//중복 방지 
            
            int c= CntSetBits(num); 
            m[c]++; 
        }
        
        long long cnt=0; 
        long long sum = 0; 
        
        auto rit = m.rbegin(); 
        for(auto it1 = m.begin(); it1 != m.end(); ++it1){
            int target = k - (*it1).first;
            
            while(rit != m.rend() && (*rit).first >= target){
                sum += (*rit).second; 
                ++rit;     
            }
            
            cnt += (*it1).second * sum;
            
        }
        
        return cnt; 
        
    }
};