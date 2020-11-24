static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int n=nums.size();

        /*
        // O(n^2) approach
        
        // Explanation:
        // arr[2] > arr[1] {LIS[2] = max(LIS [2], LIS[1]+1)=2}
        // arr[3] < arr[1] {No change}
        // arr[3] < arr[2] {No change}
        // arr[4] > arr[1] {LIS[4] = max(LIS [4], LIS[1]+1)=2}
        // arr[4] > arr[2] {LIS[4] = max(LIS [4], LIS[2]+1)=3}
        // arr[4] > arr[3] {LIS[4] = max(LIS [4], LIS[3]+1)=3}

        int t[n];
        
        for(int i=0;i<n;i++){
           t[i]=1;
        }
       
        // Same as knapsack
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
            
                if(nums[j]<nums[i])
                    t[i]=max(t[i],t[j]+1);
            
            }
        }
        
        // for(int i=0;i<n;i++){
        //         cout<<t[i]<<" ";
        // }
        
        
        return *max_element(t, t + n);
        
        */
        
        //https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/?ref=rp
        // For more optimization learn partiual patience sorting technique
        
        //OR
        
        
        // using Set
        // O(nlogn)
        set<int>s;
        // So using set the total LIS is always increasing, as we are either replacing or inserting
        // application of lower bound of set
        for(int i=0;i<n;i++){
            if(s.empty()) // First entry
                s.insert(nums[i]);
            else{
                auto set_point = s.lower_bound(nums[i]);
                if(set_point!=s.end()){ // Replace
                    s.erase(set_point);
                    s.insert(nums[i]);
                }
                else{ // Increase
                    s.insert(nums[i]);
                }
            }
        }
        return s.size();
    }
};
