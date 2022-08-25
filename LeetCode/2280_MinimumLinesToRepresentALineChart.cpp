class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        
        if(stockPrices.size()<=1) return 0; 
        sort(stockPrices.begin(), stockPrices.end());
        
        int line=1; 
        pair<long long,long long> inclien1 = {
            stockPrices[1][0]-stockPrices[0][0], 
            stockPrices[1][1]-stockPrices[0][1]
            };
        
        for(int i=2;i<stockPrices.size(); ++i){
            pair<long long,long long> inclien2 = {
            stockPrices[i][0]-stockPrices[i-1][0], 
            stockPrices[i][1]-stockPrices[i-1][1]
            };
            if(inclien1.first*inclien2.second!= inclien1.second*inclien2.first) ++line; //기울기가 다름
            inclien1=inclien2; 
        }
        
        
        return line; 
        
    }
};