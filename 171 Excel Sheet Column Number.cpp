static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        int mul=0;
        for(int i=s.length()-1;i>=0;i--){
            int x=s[i]-'A'+1;
            ans+=pow(26,mul)*x;
            ++mul;
        }
        return ans;
    }
};
