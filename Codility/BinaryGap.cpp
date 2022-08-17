// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
const int MIN = -987654321; 

int solution(int N) {
    int cnt = MIN; 
    int max_bgap = 0; 
    
    while(N>0){
        int b = N%2;
        if(b==0) ++cnt;
        else {
            max_bgap = max(max_bgap, cnt); 
            cnt = 0; 
        } 
        N=N/2; 
    }
    return max_bgap;
    // write your code in C++14 (g++ 6.2.0)
}