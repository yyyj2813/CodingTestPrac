class Solution {
public:
    int increase[4]={1, 5, 15, 60};
    int CharToInt(char c){
        return c-'0'; 
    }
    int TimeToInt(string &time){
        int h = CharToInt(time[0])*10 + CharToInt(time[1]); 
        int m = CharToInt(time[3])*10 + CharToInt(time[4]);
        return h*60+m; 
    }
    int convertTime(string current, string correct) {
        int time= TimeToInt(correct)-TimeToInt(current); 
        int cnt=0; 
        for(int i=3; i>=0; --i){
            cnt += time/increase[i];
            time = time%increase[i]; 
        }
        return cnt; 
    }
};