class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1; 
        vector<int> v; 
        
        while(l<r){
            int x = numbers[l]+numbers[r];
            if(x<target) ++l; 
            else if(x>target) --r; 
            else {
                v={l+1,r+1};
                return v; 
            }
        }
        return v; 
    }
};