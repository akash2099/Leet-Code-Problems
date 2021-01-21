static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    
    void ans(int open,int close,string curr, vector<string> &v){
        if(open==0 && close==0){
            v.push_back(curr);
            return;
        }
        
        if(open>=1){
            ans(open-1,close,curr+"(",v);
        }
        
        if(open<close){
            ans(open,close-1,curr+")",v);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        // using recursion
        vector<string>v;
        ans(n,n,"",v);
        return v;
    }
};
