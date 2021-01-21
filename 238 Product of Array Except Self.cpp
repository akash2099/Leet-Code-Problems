static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int n=nums.size();
        vector<int>res(n,1); // initialize all by one
        int start=1;
        int end=1;
        for(int i=0;i<n;++i){
            // from start multiply all
            res[i]*=start;
            start*=nums[i];
            
            // from end mltiply all
            res[n-1-i]*=end;
            end*=nums[n-1-i];
        } // can also be done in two separate loops
        return res;
    }
};
