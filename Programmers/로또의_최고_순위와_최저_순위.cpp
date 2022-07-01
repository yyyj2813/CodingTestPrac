#include <string>
#include <vector>
#include <iostream>
#include <set> 
using namespace std;
set <int> win_num_set;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    
    for(int num: win_nums) win_num_set.insert(num); 
    
    //Count matching, erased numbers; 
    int erased_cnt=0; 
    int match_cnt=0; 
    for(int lotto: lottos){
        if(lotto == 0) {
            ++erased_cnt; 
            continue; 
        }
        if(win_num_set.find(lotto) != win_num_set.end()) ++match_cnt;
    }

    int best= (match_cnt+erased_cnt>=2)? (7-(match_cnt+erased_cnt)): 6;
    int worst = (match_cnt>=2)?(7-match_cnt): 6; 

    vector<int> answer= {best,worst};
    
    return answer; 
}