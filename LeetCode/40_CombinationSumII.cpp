class Solution {
public:
    vector<vector<int>> ans; 
    void Combination(map<int, int>& candidates, map<int, int>::iterator it, int left, vector<int>&vec){
        if(left<0) return; 
        else if(left ==0 ) {
            ans.push_back(vec);
            return; 
        }
        else if (it==candidates.end()) return;
        
        int cnt = (*it).second;
        auto nxt_it=it; ++nxt_it;
        
        for(int i=0; i<=cnt; ++i){
            Combination(candidates, nxt_it, left-(*it).first *i, vec); 
            vec.push_back((*it).first); 
        }
        
        for(int i=0; i<=cnt; ++i) vec.pop_back(); 
    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vec; 
        map<int, int> m; 
        for(int cand: candidates) m[cand]++;
        
        
        Combination(m, m.begin(), target, vec);
        
        return ans; 
    }
};