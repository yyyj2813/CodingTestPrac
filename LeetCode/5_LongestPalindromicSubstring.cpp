const int MIN=-987654321; 
class Solution {
public:
    int g_max; 
    int g_s=0,g_e=0; 
    
    string longestPalindrome(string s) {
        int n =s.size(); 
        vector<vector<int>>dp;
        dp.assign(n, vector<int>(n,-1)); 
        
        for(int i=0; i<n;++i) dp[i][i]=1; 
        
        for(int i=n-1; i>=0; --i){
            for(int j=i+1; j<n; ++j){
                dp[i][j]=0;      
                
                if(s[i]==s[j] && dp[i+1][j-1]==1) dp[i][j]=1;
                if(s[i]==s[j] && j==i+1) dp[i][j]=1; 
                    
                if(dp[i][j]==1 && (j-i+1)>g_max) {
                    g_max = j-i+1; 
                    g_s=i;
                    g_e=j; 
                }
            }
        }
        
        return s.substr(g_s, g_e-g_s+1);
    }
};