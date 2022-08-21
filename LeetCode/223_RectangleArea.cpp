class Solution {
public:
    int CalcArea(int x1, int y1, int x2, int y2){
        if(y2<=y1) return 0; 
        if(x2<=x1) return 0; 
        return (y2-y1)*(x2-x1); 
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int cx1= max(ax1, bx1); 
        int cy1= max(ay1, by1);
        
        int cx2= min(ax2, bx2);
        int cy2= min(ay2, by2);
        
        int area1= CalcArea(ax1,ay1,ax2,ay2);  
        int area2= CalcArea(bx1,by1,bx2,by2); 
        int overlapped_area= CalcArea(cx1,cy1,cx2,cy2);
        
        
        return area1+area2-overlapped_area;        
    }
};