class Solution {
public:
    
    vector<int> window; 
    vector<vector<int>::iterator> its; 
    
    void Insert(int x){
        auto it = upper_bound(window.begin(), window.end(), x); 
        window.insert(it,x);
    }
    void Delete(int x){
        auto sit= window.begin();
        auto eit = window.end()-1; 
        while(sit<=eit){
            auto mit= sit+(eit-sit)/2;
            if((*mit)==x) {
                window.erase(mit);
                return; 
            }
            else if((*mit)<x) sit=mit+1; 
            else eit=mit-1; 
        }
    }
    
    double GetMedian(){
        double ret=0; 
        for(auto & it : its) ret+= (*it); 
        return ret/its.size(); 
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        vector<double> ans; 
        
        //초기화 
        for(int i=0; i<k;++i) window.push_back(nums[i]);
        sort(window.begin(), window.end());
        
        if(k%2==0) its.push_back(window.begin()+k/2-1); 
        its.push_back(window.begin()+k/2); 
        
        ans.push_back(GetMedian());
        
        for(int i=0; i<nums.size()-k; ++i){
            Delete(nums[i]);
            Insert(nums[i+k]);
            ans.push_back(GetMedian());
        }
        
        
        return ans; 
        
    }
};