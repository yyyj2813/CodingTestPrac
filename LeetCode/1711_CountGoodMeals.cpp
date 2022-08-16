#include <cmath> 
#include <map>
const long long MOD = pow((long long)10, 9) + 7; 
const int pow_limit=22; 
class Solution {
public:
    long long Comb(long long n){
        return n*(n-1)/2; 
    }
    int countPairs(vector<int>& deliciousness) {
        vector<int> pow2; 
        int s=1; 
        for(int i=0; i<pow_limit; ++i){
            pow2.push_back(s); 
            s*=2; 
        }
        
        map<int,int> m; 
        for(int d:deliciousness) m[d]++;
        
        
        int cnt=0; 
        for(auto it =m.begin(); it!=m.end(); ++it){
            for(int i=0; i<pow_limit; ++i){
                int target = pow2[i]-(*it).first; 
                if(target < (*it).first) continue; 
                
                auto it2= m.find(target); 
                if(it2==m.end()) continue; 

                if(it2==it) cnt= (cnt+Comb((*it).second)%MOD )%MOD;
                else cnt = (cnt+ (*it).second*(*it2).second%MOD) %MOD; 
            }
        }
        return cnt; 
        
    }
};