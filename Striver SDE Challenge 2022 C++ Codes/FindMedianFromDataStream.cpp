class MedianFinder {
public:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    void addNum(int num) {
        //elements lesses than mid to the left,i.e.,in maxHeap
        if(maxHeap.empty() or num<=maxHeap.top()) maxHeap.push(num);
        //elements greater than mid to the right,i.e.,in minHeap
        else minHeap.push(num);
        //there should be only 1 extra element in maxHeap than minHeap
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // there should be no extra elements in minHeap than maxHeap
        if(maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()){
            double mid=(minHeap.top()+maxHeap.top())/2.0;
            return mid;
        }
        else return maxHeap.top();
    }
};