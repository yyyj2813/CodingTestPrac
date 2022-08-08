#include <algorithm> 
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        unordered_map<string,vector<string>> m; 
        for(int i=0; i<strs.size(); ++i){
            string key = strs[i];
            sort(key.begin(), key.end());
            
            if(m.find(key)==m.end()) {
                m[key] = vector<string>(); 
                m[key].push_back(strs[i]);
                continue; 
            }
            else{
                auto & v = m[key];
                v.push_back(strs[i]);
            }
            
        }
        
        for(auto it =m.begin(); it!=m.end(); ++it){
            ans.push_back((*it).second);
        }
        
        
        return ans;
    }
};