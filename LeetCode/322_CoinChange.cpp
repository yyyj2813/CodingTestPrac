#include <unordered_map>
const int MAX=987654321;
class Solution {
public:
    unordered_map<int, int> m; 
    int TopDown(vector<int>& coins, int amount) {
        if(amount==0) return 0; 
        if(amount<0) return MAX;
        
        if(m.find(amount)!=m.end()) return m[amount];
        
        int ret =MAX; 
        for(int i=0; i<coins.size(); ++i){
            ret= min( 1+TopDown(coins, amount-coins[i]), ret);
        }
        
        m[amount]=ret; 
        
        return ret; 
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int ret =TopDown(coins, amount);
        if(ret>=MAX) return -1;
        else return ret; 
    }
    
};