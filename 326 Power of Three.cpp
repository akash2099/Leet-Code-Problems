static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<0 || !n)
            return false;
        
        while(n>1){
            if(n%3!=0)
                return false;
            n/=3;
        }
        return true;
        
    }
};
