class Solution {
public:
    
    int increase(vector<int>& cost, int s, int e){
        int total=0; 
        for(int y= s+1; y<= e;++y){
            total+=cost[y]; 
        }
        return total; 
    }
    int decrease(vector<int>& cost, int s, int e){
        int total=0; 
        for(int y= s-1; y>=e; --y){
            total+=cost[y]; 
        }
        return total; 
    }
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost=0; 
        
        if(startPos[0]<homePos[0]) cost+= increase(rowCosts,startPos[0],homePos[0] ); 
        else cost+=decrease(rowCosts,startPos[0],homePos[0] ); 
        
        if(startPos[1]<homePos[1])cost+= increase(colCosts,startPos[1],homePos[1] ); 
        else cost+=decrease(colCosts,startPos[1],homePos[1] ); 
        
        return cost; 
        
    }
};