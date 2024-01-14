class MedianFinder {
public:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh; 

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh.empty()||maxh.top()>num){
            maxh.push(num);
        }
        else{
            minh.push(num);
        }
        if(maxh.size()<minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }else if(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
    }
    
    double findMedian() {
        double ans=0;
        if(maxh.size()!=minh.size())return maxh.top();
        else{
            ans=(double)(minh.top()+maxh.top())/2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */