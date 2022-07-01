#include <string>
#include <vector>
#include <iostream>
using namespace std;
char cand[3]={'.','-','_'};


bool ValidChar(char c){
    if( isalpha(c) || isdigit(c) )   return true; 
    for(int i=0; i<3; ++i) {
        if(c==cand[i]) return true; 
    }
    return false; 
}

string solution(string new_id) {    
    //stage 1
    for(auto & c : new_id) c = tolower(c);
    
    //stage 2 
    for(auto it=new_id.begin(); it!=new_id.end(); ){
        if(ValidChar(*it)) ++it; 
        else it = new_id.erase(it);
    }
    
    //stage 3 
    bool had_dot=false; 
    for(auto it=new_id.begin(); it!=new_id.end(); ){
        if((*it)=='.'){
            if(had_dot){
                it = new_id.erase(it);
                continue; 
            }
            had_dot=true; 
        }
        else had_dot=false; 
        ++it; 
    }
    //stage 4
    
    while(!new_id.empty() && new_id.front() == '.') new_id.erase(new_id.begin());
    while(!new_id.empty() && new_id.back() == '.') new_id.pop_back();
    
    //stage 5
    if(new_id.size()==0) new_id="a";
    
    //stage 6
    else if (new_id.size()>=16){
        new_id=new_id.substr(0, 15);
    }
    while( !new_id.empty() && new_id.back() == '.') new_id.pop_back();

    
    //stage 7
    if(new_id.size()<=2) {
        while(new_id.size()<3) new_id+=new_id.back(); 
    }
    
    return new_id; 
    
}
