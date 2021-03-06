static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int solve(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int>v(n);
        if(n>=1)
            v[0]=nums[0];
        if(n>=2)
            v[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;++i){
            v[i]=max(v[i-1],nums[i]+v[i-2]);
        }
        return v[n-1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>a (nums.begin()+0,nums.end()-1);
        vector<int>b (nums.begin()+1,nums.end());
        return max(solve(a),solve(b));
    }
};
