#include <string>
#include <vector>
using namespace std;

const int MAX=1000000001;
int solution(vector<int> a) {
    //a[idx]의 좌 우로 가장 작은 값 구하기 
    vector<int> right_min(a.size(), MAX); //right_min[i]= [0,i]까지 최솟값
    vector<int> left_min(a.size(), MAX); //left_min[i]= [i,a.size()-1]까지 최솟값
    
    int mval = MAX; 
    for(int i=0; i< a.size(); ++i){
        mval=min(mval, a[i]);
        right_min[i]=mval; 
    }
    
    mval=MAX; 
    for(int i=a.size()-1; i>=0; --i){
        mval=min(mval, a[i]);
        left_min[i]=mval; 
    }
    
    int cannot_survive=0; 
    for(int i=1; i<a.size()-1; ++i){//양끝은 항상 살아남음 
        if(a[i]>right_min[i-1] && a[i]> left_min[i+1]) cannot_survive++; //불가능  
    }
    
       
    return a.size()-cannot_survive;
}