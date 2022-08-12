class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1) return 1;
        
        int max_len=0;
        int len=0; 
        
        int bf_state=0; 

        
        for(int j=1; j<arr.size(); ++j){
           
            int now_state= 0; 
           
            if(arr[j-1]<arr[j]) now_state=1;
            else if(arr[j]<arr[j-1]) now_state=-1;
            
            if(now_state==0) len=0;
            else if(bf_state==now_state) len=1;
            else ++len; 
            
            max_len=max(max_len, len);
            
            bf_state = now_state;
        }
        return max_len+1;       
    }
};
