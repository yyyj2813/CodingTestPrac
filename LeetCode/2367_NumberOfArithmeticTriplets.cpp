#include <set> 
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int> s;
        int cnt=0; 
        for(int num: nums) s.insert(num); 
        
        for(auto it1= s.begin(); it1!=s.end(); ++it1){
            int target1= (*it1)+diff; 
            int target2= (*it1)+2*diff; 
            if(s.find(target1)!= s.end() && s.find(target2)!=s.end()) ++cnt;
        }
        return cnt; 
    }
};