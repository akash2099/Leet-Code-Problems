static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // using xor
        int res=0;
        for(int v:nums){
            res^=v;// the values which are present twice will get cancel out
        }
        return res;
    }
};
