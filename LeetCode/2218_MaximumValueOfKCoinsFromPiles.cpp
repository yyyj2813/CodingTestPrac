const int MIN=-987654321;
class Solution {
public:
    
    vector<vector<int>> cache; 
    int GetMax(vector<vector<int>> &piles, int idx, int left){
        
        if(left == 0) return 0; 
        if(idx == piles.size()) return MIN; 
        
        int &ret = cache[idx][left];
        
        if(ret != -1) return ret; 
        ret = 0; 
        
        int take_limit = min((int)piles[idx].size()-1, (int)left); 
        
        for(int take=0; take <= take_limit; ++take){
            ret = max(ret, piles[idx][take] + GetMax(piles, idx+1, left-take)); 
        }
        
        return ret; 
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> pre(n, vector<int>()); 
        cache.assign(n, vector<int>(k+1, -1));
        
        for(int i=0; i<piles.size(); ++i){
            auto & q = piles[i]; 
            
            int p=0; 
            int sum=0; 
            pre[i].push_back(sum);//0개 선택 시 
            
            while(p<=k && p< q.size()){
                sum += q[p];
                pre[i].push_back(sum); 
                ++p; 
            }
        }
        
        int ret = GetMax(pre, 0, k);
        return ret; 
    }
};