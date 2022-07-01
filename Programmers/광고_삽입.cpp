#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int cnt[360000];//[시간]에 따른 재생 수
long long TimeToInt(string time){
    int hour = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    int sec = stoi(time.substr(6,2)); 
    return (long long ) hour*3600+min*60+sec; 
}
string IntToTime(int timeint){
    int sec= timeint%60;
    timeint/=60; 
    int min=timeint%60; 
    int hour= timeint/=60; 
    string ret="";
    
    if(hour<10) ret += "0";
    ret+=to_string(hour)+":";
    
    if(min<10) ret += "0";
    ret+=to_string(min)+":";
    
    if(sec<10) ret += "0";
    ret+=to_string(sec);
    
    return ret;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    memset(cnt, 0, sizeof(cnt));
    string answer = "";
    for(string log: logs){
        int stime= TimeToInt(log.substr(0,8));
        int etime= TimeToInt(log.substr(9,8));
        
        for(int idx = stime; idx < etime; ++idx){
            cnt[idx]++; 
        }
    }
    
    int play_length = TimeToInt(play_time);
    int adv_length = TimeToInt(adv_time); 
    
    if(adv_length == play_length) return IntToTime(0);
    
    long long total=0; 
    //0초 시작 시 누적재생시간  
    for(int t=0; t<adv_length; ++t){
        total += cnt[t];   
    }
    
    long long max_total = total;
    int stime = 0; 
    //한 칸씩 이동
    for(int t=1; t<=play_length-adv_length+1; ++t){
        total=total-cnt[t-1]+cnt[t+adv_length-1];
        if(total > max_total){
            max_total=total;
            stime=t; 
        }
    }
    
    return IntToTime(stime);
}