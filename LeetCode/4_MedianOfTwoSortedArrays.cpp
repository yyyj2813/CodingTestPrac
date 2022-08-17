class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x= (nums1.size()+ nums2.size());/
        
        int goal = x/2;
        
        auto it1 =nums1.begin(); 
        auto it2 = nums2.begin(); 
        int idx = 0; 
        int median =0; int median2=0; 
        while( true ){         
            int now=0;
            if(it1!=nums1.end() && it2!=nums2.end()){ 
                if(*it1>*it2) {
                    now=*it2;
                    ++it2; 
                }
                else {
                    now = *it1; 
                    ++it1; 
                }
            }
            else if(it1==nums1.end()){
                now= *it2;
                ++it2; 
            }
            else if(it2==nums2.end()){
                now= *it1;
                ++it1; 
            }
            
            if(idx == goal-1){
                median2=now; 
            }    
            else if( idx == goal ){  
                median=now; 
                break;
            }
            
            ++idx;
            
        }
        
        if(x%2 == 0)  return ((double)median+(double)median2)/2;
        else return median; 
    }
};