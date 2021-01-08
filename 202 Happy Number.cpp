static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int square_sum(int n)
    {
        int res=0;
        while (n)
        {
            int t = n % 10;
            res += t*t;
            n/=10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        unordered_map<int,int>m;
        while (m[n]!=2) {
            if (n == 1) return true;
            n = square_sum(n);
            m[n]++;
            // cout<<n;
        }

        return false;
    }
    // Using Floyd detection algorithm for linked list cycle detection left
};
