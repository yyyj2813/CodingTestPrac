class Solution {
public:
    vector<vector<int>> ans; 
    int n; 
    void MakeComb(vector<int> & vec, int x, int left){
        if(left==0) {
            ans.push_back(vec);
            return ; 
        }
        
        for(int i=x; i<=n; ++i){
            vec.push_back(i);
            MakeComb(vec, i+1, left-1);
            vec.pop_back(); 
        }
        
        
    }
    vector<vector<int>> combine(int N, int K) {
        n=N; 
        vector<int> vec;
        MakeComb(vec, 1, K); 
        return ans; 
    }
};