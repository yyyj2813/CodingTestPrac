#include <string>
#include <vector>
#include <map> 
#include <cmath>
#include <iostream>
using namespace std;

struct tree{
    string name; 
    tree * p; 
    int total = 0; 
    tree():name(""),p(this){
    }
    tree(string s): name(s),p(this){
    }
    void SetParent(tree * pa){
        p = pa; 
    }
};

void Distribute(tree * t, int amount){
    if(t->p == t) return; //root인 경우
    if(amount == 0 ) return; 

    int dis_amount= floor(amount*0.1);
    (t->total) += amount-dis_amount;
    
    Distribute(t->p,dis_amount);
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    map<string, tree> m;//이름, tree  
    
    m["-"] = tree("-");//"-"는 minho 
    
    for(int i=0; i<referral.size(); ++i){
        m[enroll[i]] = tree(enroll[i]);//구성원 tree 생성
        m[enroll[i]].SetParent( &m[referral[i]]); //tree의 parent 설정
    }
    
    for(int i=0; i<seller.size(); ++i){
        Distribute( &m[seller[i]], amount[i]*100);
    }
    
    vector<int> answer;
    for(auto ppl : enroll) answer.push_back( (m[ppl].total) );
    
    return answer;
}