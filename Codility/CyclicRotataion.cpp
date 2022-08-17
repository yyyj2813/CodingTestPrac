// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    int n = A.size(); 
    if(n == 0) return A; 
    
    K=K%n; 
    if(K == 0) return A; 
    
    while(K>0){
        int x = A.back(); 
        A.pop_back(); 
        A.insert(A.begin(), x); 
        --K; 
    }
    return A; 
    // write your code in C++14 (g++ 6.2.0)
}