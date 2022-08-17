#include <unordered_map>
int solution(vector<int> &A) {
    unordered_map<int, int> m; 
    for(int n : A) m[n]++; 

    for(auto it= m.begin(); it!=m.end(); ++it){
        if((*it).second%2==1) return (*it).first; 
    }
    return -1; 

    // write your code in C++14 (g++ 6.2.0)
}