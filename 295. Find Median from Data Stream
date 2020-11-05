static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue <int, vector<int>, greater<int> > minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // push the larger nums into minHeap and 
        // smaller nums into maxHeap, so both of their top will contian the middle element(s)
        
        // Initializing the first two nums
        if(minHeap.size()==0){
            minHeap.push(num);
            return;
        }
        if(maxHeap.size()==0){
            if(num<minHeap.top()){
                maxHeap.push(num);                
            }
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            return;
        }
        
        // Main code
        if(num<minHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        
        balance();
    }
    
    void balance(){
        // balance the heaps if required
        if(abs((int)(minHeap.size()-maxHeap.size()))<=1) // for abs typecast it to int
            return;
        else if(maxHeap.size()>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else{
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        //calculate the median according to the size of Heap
        if(maxHeap.size()>minHeap.size())
            return maxHeap.top();
        else if(maxHeap.size()<minHeap.size())
            return minHeap.top();
        
        return (maxHeap.top()+minHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
