class Solution {
public:
    int maxArea(vector<int>& height) {
        auto b = height.begin(); 
        auto e = height.end()-1; 
        
        int max_area=0; 
        
        while(b<e){
            int area= min( (*e),(*b)) *(e-b);    
            
            if((*b) <= (*e)) ++b;
            else --e; 
            max_area = max(max_area, area);
        }
        return max_area;
        
    }
};