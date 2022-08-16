class Solution {
public:
    int BinarySearch(vector<int>& arr, int s, int e, int target){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid] == target) return mid; 
            else if(arr[mid] < target) s = mid+1; 
            else e = mid-1; 
        }
        return -1; 
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> arr(2,0); 
        for(int now=0; now<numbers.size(); ++now){
            int to_find = target-numbers[now]; 
            if(to_find<numbers[now]) continue; 
            int s = now+1; 
            int e = numbers.size()-1; 
            
            int tidx= BinarySearch(numbers, s,e, to_find); 
            if(tidx!=-1){
                arr[0]=now+1; 
                arr[1]=tidx+1; 
               return arr; 
            }
        }
        return arr; 
    }
};