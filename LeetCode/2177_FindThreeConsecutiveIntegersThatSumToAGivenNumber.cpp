class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3==0){
            long long x= num/3;
            vector<long long> vec{x-1,x,x+1};
            return vec; 
        }
        return vector<long long>(); 
    }
};