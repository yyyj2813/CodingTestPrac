#include <map>
#include <algorithm> 
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string ,int> m; 
        for(int i=0; i<messages.size(); ++i){
            string &s= messages[i]; 
            int cnt=1; 
            for(char &c: s){
                if(c==' ') ++cnt; 
            } 
            m[senders[i]] +=cnt; 
        }
        
        vector<pair<int, string>> v; 
        for(auto it = m.begin(); it!=m.end(); ++it){
            v.push_back({(*it).second, (*it).first});    
        }
        auto mit=max_element(v.begin(), v.end());
        return (*mit).second; 
    }
};