class MedianFinder {
public:
    priority_queue<int>maxH;
    priority_queue<int,vector<int>,greater<int>>minH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(maxH.empty()) {
        maxH.push(num);
        return;
       }
       if(num<=maxH.top()) {
        maxH.push(num);
       } else {
        minH.push(num);
       }
       if(minH.size()>maxH.size()){
        maxH.push(minH.top());
        minH.pop();
       } else if(maxH.size()-1>minH.size()){
        minH.push(maxH.top());
        maxH.pop();
       }
    }
    
    double findMedian() {
        if(minH.size()==maxH.size()) {
            return 1.0*(minH.top()+maxH.top())/2.0;
        }
        return 1.0*maxH.top();
    }
};
