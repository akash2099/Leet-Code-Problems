static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        int t[n];
        t[0]=1;
        t[1]=2;
        
        for(int i=2;i<n;i++){
            t[i]=t[i-1]+t[i-2];
        }
        
        return t[n-1];
        
    }
};
