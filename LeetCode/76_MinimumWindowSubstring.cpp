#include <unordered_map> 
#include <queue> 
const int MAX=987654321;
class Solution {
public:
    int n; 
    int ans_s, ans_e; 
    
    int GetMinIdx(unordered_map<char, queue<int>> &m){
        int min_idx=n;
        for(auto it=m.begin(); it!=m.end(); ++it){
            queue<int> & now_vec=(*it).second;
            if(now_vec.front()==-1) return -1; 
            min_idx=min(min_idx, now_vec.front());
        }
        return min_idx; 
        
    }
    int UpdateIdx(unordered_map<char, queue<int>> &m, int c, int idx){
        queue<int> & q = m[c];
        int bf = q.front(); q.pop(); 
        q.push(idx);
        return bf;
    }
    string minWindow(string word, string t) {
        n=word.size(); 
        ans_s=ans_e=-1;
        
        unordered_map<char, int> key; //필요로 하는 알파벳과 개수
        for(char c: t) key[c]++;
        
        unordered_map<char, queue<int>> idx_map;
        for(char c: t) {
            idx_map[c] = queue<int>();
            for(int i=0; i<key[c]; ++i) idx_map[c].push(-1);
        }
        
        
        int s=-1; 
        int min_len=MAX; 
        for(int e=0; e<word.size(); ++e){
            char now = word[e];
            if(key.find(now) == key.end()) continue; 
            
            int t= UpdateIdx(idx_map, now, e);
            
            int uidx = GetMinIdx(idx_map);
            if(uidx==-1) continue; //조건 충족하지 못함
            
            s = uidx;
            // cout<<"s="<<s<<"e="<<e<<" char="<<word[e]<<" uidx="<<uidx<<" t="<<t<<endl;
            
            if(e-s+1 <min_len){
                min_len = e-s+1; 
                ans_e=e; ans_s=s; 
            }
        }
        
        if(ans_s==-1 && ans_e==-1) return "";
        return word.substr(ans_s, ans_e-ans_s+1);
    }
};