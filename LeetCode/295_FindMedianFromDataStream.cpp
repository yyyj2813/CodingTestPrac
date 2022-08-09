#include <queue> 
class MedianFinder {
public:
    priority_queue<int> lpq; //작은
    priority_queue<int, deque<int>, greater<int>> gpq; //큰 
    MedianFinder() {
        
    }
    
    void addNum(int now) {
        //cout<<"Insert "<<now<<endl;
        if(gpq.empty()) gpq.push(now);
        else if (gpq.top()<=now) gpq.push(now);
        else lpq.push(now);
        
        
        if(gpq.size()==lpq.size()) return; 
        else if(lpq.size() > gpq.size()) {
            gpq.push(lpq.top()); 
            lpq.pop(); 
        }
        else if(gpq.size()-lpq.size() >= 2){
            lpq.push(gpq.top()); 
            gpq.pop(); 
        }
        
        //cout<<lpq.size()<<' '<<gpq.size()<<endl;
        
    }
    
    double findMedian() {
        //cout<<"findMedian"<<lpq.size()<<' '<<gpq.size()<<endl;   
        
        if(lpq.size()==gpq.size()) return ((double)lpq.top() + gpq.top())/2.0;
        else return gpq.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */