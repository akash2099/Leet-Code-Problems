static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class MinStack {
public:
    /** initialize your data structure here. */
    long long me=-1; // min element
    // int count=0;
    stack<long long>s;
    
    MinStack() {
        // stack<int>s;
    }
    
    void push(int x) {
        // cout<<++count;
        if(s.size()==0){
            s.push(x);
            me=x;
        }
        else if(me<=x){
            s.push(x);
        }
        else{
            s.push(x-me+x);
            me=x;
        }
    }
    
    void pop() {
        if(s.size()==0){
            me=-1;
        }
        else if(s.top()<me){
            me=me-s.top()+me;
            s.pop();
        }
        else{
            s.pop();
        }
    }
    
    int top() {
        if(s.size()==0)
            return -1;
        else{
            if(s.top()<me)
                return me;
            else
                return s.top();
        }
    }
    
    int getMin() {
        if(s.size()==0){
            return -1;
        }
        else{
            return me;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
