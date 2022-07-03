class Solution {
public:
    int cache[46];
    
    int climb(int n ){
        if(n<=1) return 1;
        
        int & ret = cache[n];
        if(ret != -1) return ret; 
        
        return ret = climb(n-1)+ climb(n-2);;
    }
    int climbStairs(int n) {
        memset(cache,-1, sizeof(cache)); 
        return climb(n);
    }
};