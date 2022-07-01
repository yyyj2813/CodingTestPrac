#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int CntZero(string &s){
    int cnt=0; 
    for(char c: s){
        if(c=='0')++cnt; 
    }
    return cnt; 
}
string BinaryExp(int num){
    if(num==0) return "";
    return BinaryExp(num/2)+to_string(num%2);
}
vector<int> solution(string s) {
    
    int conv_cnt=0; //이진 변환의 횟수
    int rmv_zcnt=0; //제거된 0의 개수 
    
    while( s!= "1" ){
        int cnt = CntZero(s); 
        rmv_zcnt += cnt; 
        s = BinaryExp( s.size()-cnt );
        ++conv_cnt;     
    }
    
    
    
    vector<int> answer={conv_cnt, rmv_zcnt};//이진 변환의 횟수,제거된 0의 개수 
    return answer;
}