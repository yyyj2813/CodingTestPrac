#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int OrderToInt(string & s){//bitmask 
    int order=0; 
    for(char c: s){
        order += 1<<(c-'A');
    }
    return order; 
}
string IntToOrder(int i, int cnt=0){
    if(i==0) return "";
    
    if(i%2==1) {
        string s="A";
        s[0] = ('A'+cnt);
        return s+ IntToOrder(i/2,cnt+1);
    }
    else return IntToOrder(i/2, cnt+1);
}
int CntMenu(int s){
    if(s==0) return 0; 
    return s%2+CntMenu(s/2);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<int> bmask_order;//구성을 bitmask로 표현 
    for(string order:orders) bmask_order.push_back(OrderToInt(order)); 

    map<int,int> m; //m[구성]= 주문 수 
    for(int order: bmask_order) {
        for(int subset=order; subset; subset= (subset-1) & order){
            m[subset]++; 
        }
    }
    
    vector<vector<pair<int,int>>>dvec(11, vector<pair<int,int>>()); // dvec[메뉴 개수] = { (주문 수, 구성),...} 
    
    for(auto mit=m.begin(); mit!=m.end(); ++mit){
        
        if((*mit).second < 2) continue; //2명 이하의 손님으로부터 주문
        
        int cnt= CntMenu( (*mit).first );
        if(cnt < 2) continue; //메뉴 구성 2개 이하 
        
        dvec[cnt].push_back({(*mit).second, (*mit).first});
    }
    
    vector<string> answer; 
    //메뉴 개수 별 최고 주문 수 
    for(int course_cnt: course){
        auto & v =dvec[course_cnt];
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        
        int max_val = v[0].first; 
        for(auto it = v.begin(); it!=v.end(); ++it){
            if((*it).first !=max_val) break; 
            answer.push_back(IntToOrder((*it).second));
        }
            
    }
    sort(answer.begin(), answer.end());
    
    return answer; 
    
}