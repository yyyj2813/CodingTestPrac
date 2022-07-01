#include <string>
#include <vector>
#include <map> 
#include <algorithm> 
using namespace std;

vector<int> solution(vector<int> numbers) {
    map <int,int> m;
    for(int num: numbers){
        m[num]++;
    }
    
    auto it1 = m.begin(); 
    auto it2 = m.begin(); 

    vector<int> answer; 
    for(;it1!=m.end();++it1){
        for(it2=it1; it2!=m.end(); ++it2){
            if(it2==it1 && (*it1).second<2 ) continue; 
            answer.push_back((*it1).first+(*it2).first) ; 
        }
    }
    
    sort(answer.begin(), answer.end());
    auto it= unique(answer.begin(), answer.end());
    return vector<int>(answer.begin(), it);
}