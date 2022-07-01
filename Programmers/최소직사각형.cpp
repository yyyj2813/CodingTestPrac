#include <string>
#include <vector>
#include <algorithm> 
using namespace std;
const int MIN=-987654321;
int solution(vector<vector<int>> sizes) {
    int max_h=MIN; 
    vector<int> small; 
    for (auto c : sizes){
        int smaller=1; 
        if(c[0]<c[1]) smaller=0;
        
        small.push_back(c[smaller]);
        max_h=max(max_h,c[1-smaller]);
    }
    sort(small.begin(), small.end(), greater<int>());
    
    int answer = small[0]*max_h;
    return answer;
}