static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k = k%n;
        
        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        reverse(nums.begin(), nums.begin() + n - k);

        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        reverse(nums.begin() + n - k, nums.begin() + n);

        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        reverse(nums.begin(), nums.begin() + n);
        
        
        // Another Approach:
        // k %=nums.size();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin()+k);
        // reverse(nums.begin()+k, nums.end());
    
    }
};
