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
        
        string o1=curr;
        string o2=curr;

        if(open>=1){
            o1.push_back('(');
            ans(open-1,close,o1,v);
        }
        
        if(open<close){
            o2.push_back(')');
            ans(open,close-1,o2,v);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        // using recursion
        vector<string>v;
        ans(n,n,"",v);
        return v;
    }
};
