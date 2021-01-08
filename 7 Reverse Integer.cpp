static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        x = abs(x);
        int res = 0;
        int rem;
        while (x > 0) {
            
            // checking int extreme values
            if (INT_MAX/10 < res || (INT_MAX - x % 10) < (res * 10)) {
                return 0;
            }
            
            res = res * 10 + x % 10;
            x /= 10;
        }
        
        return sign * res;
    }
};
