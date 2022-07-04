class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0; 
       
        int max_profit=0; 
        
        int m_after = prices[prices.size()-1]; //i+1~마지막 까지 중 최댓 값
        
        for(int i=prices.size()-2; i>=0; --i){
            max_profit = max(max_profit, m_after-prices[i]);
            m_after=max(prices[i], m_after);
        }
        return max_profit; 
        
    }
};