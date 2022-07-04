#include <algorithm>
#include <vector>
#include <unordered_map> 
using namespace std;
int n; 
int solution(vector<int> nums)
{
    n = nums.size(); 
    unordered_map<int,int> m;
    for(int n : nums) m[n]++; 
    
    
    int answer = min( (int)n/2, (int)m.size() ) ;
    return answer;
}