class Solution {
public:
    
    
    int DP(vector<int> &cache, int n){
        if(n<=1) return n; 
        
        int & ret=cache[n]; 
        if(ret!=-1) return ret;
        
        ret = DP(cache, n/2) + n%2;
        return ret; 
    }
    
    vector<int> countBits(int n) {
        
        vector<int> cache(n+1, -1);
        cache[0]=0; 
        if(n==0) return cache; 
        
        cache[1]=1;
        
        for(int i=0; i<=n; ++i) DP(cache, i);
        return cache; 
    }
};