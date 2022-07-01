#include <string>
#include <vector>
#include <iostream>
#include <deque> 
using namespace std;
const int MAX=987654321;
vector<vector<int>> board;

int Rotate( vector<pair<int,int>>& order){
    deque<int> dq; 
    int min_val=MAX; 
    for(auto coord: order){
        int x= board[coord.first][coord.second]; 
        min_val=min(x,min_val);
        dq.push_back(x);
    }
    int b = dq.back(); 
    dq.pop_back(); 
    dq.push_front(b);
    
    for(auto coord: order){
        if(dq.empty()) return -1; 
        board[coord.first][coord.second]=dq.front(); 
        dq.pop_front(); 
    }
    return min_val; 
}
vector<pair<int,int>> GetAccessOrder(int x1, int y1, int x2, int y2){
    vector<pair<int,int>> order; 
    for(int y=y1; y<y2; ++y) order.push_back({x1, y});
    for(int x=x1; x<x2; ++x) order.push_back({x, y2});
    for(int y=y2; y>y1; --y) order.push_back({x2, y});
    for(int x=x2; x>x1; --x) order.push_back({x, y1});
    return order; 
    
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    board.assign(rows, vector<int>(columns, 0));
    int cnt=0; 
    for(int y=0; y<rows; ++y){
        for(int x=0; x<columns; ++x) {
            ++cnt; 
            board[y][x]=cnt; 
        }
    }
    vector<int> answer;
    for(auto q: queries){
        auto order = GetAccessOrder(q[0]-1, q[1]-1, q[2]-1, q[3]-1); 
        answer.push_back(Rotate(order));
    }
    return answer;
}