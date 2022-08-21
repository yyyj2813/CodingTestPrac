class Solution {
public:
    int MakeIncreasingVec(vector<int>& vec){
        vector<int> inc_v;
        inc_v.push_back(vec[0]);
        int ans=1; 
        for(int i=1; i<vec.size();++i){
            if(inc_v.back()<=vec[i]) { 
                inc_v.push_back(vec[i]);
                ++ans; 
            }
            else {
                auto it= lower_bound(inc_v.begin(), inc_v.end(), vec[i]);
                while((*it) == vec[i])++it; 
                (*it)=vec[i];
            }
        }
        for(int x: inc_v)cout<<x<<' ';
        return vec.size()-ans; 
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        vector<vector<int>> vecs(k, vector<int>()); 
        
        for(int idx=0; idx<arr.size(); ++idx){
            vecs[idx%k].push_back(arr[idx]); 
        }
        
        int cnt=0;
        for(auto & v:vecs){
            cnt+=MakeIncreasingVec(v);   
        }
        
        return cnt;   
        
    }
};