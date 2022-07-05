vector<vector<int>> cache; 
class Solution {
public:
    
    
    int CalcComb(int n, int a){//n!/(a!b!) 
        if(a<=0) return 1;
        if(a==1) return n; 
        
        int &ret = cache[n][a];
        if(ret!=-1) return ret; 
        
        return ret = CalcComb(n-1, min(n-1-a,a)) + CalcComb(n-1,min(n-a,a-1));
    }
    int uniquePaths(int m, int k) {
        //a+bCa
        int a = m-1; 
        int b = k-1; 
        int n = a+b; 
        
        cache.assign(n+1, vector<int>( n/2 +1,-1)); //n=6 6C3까지-> 4 n=7 7C3까지 ->4  
        
        int ret = CalcComb(n, min(a,b));

        return ret; 
    }
};