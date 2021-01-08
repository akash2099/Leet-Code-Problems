static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int trailingZeroes(int n) {
        // Time: O(logn base 5)
        int sum=0;
        while(n){
            sum+=n/5;
            n=n/5;
        }
        return sum;
    }
};
