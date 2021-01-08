static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Without using extra space, Time: O(n),Space: O(1)
        // Math
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        int full_sum=((n+1)*n)/2;
        return full_sum-sum;
        
        
        // Without using extra space, Time: O(n),Space: O(1)
        // Bit Manipulation
    }
};
