static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        int n=arr.size();
        
        vector<int>t(n);// By default it get initialised by 0

        // Here I am considering for every index i,t[i] will contain the maximum total 
        // subarray sum upto i size array
        
        // Top-Down
        for (int i = 0; i < n; ++i) {
            int curMax = 0;
            for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
                curMax = max(curMax, arr[i - k + 1]);
                t[i] = max(t[i], (i >= k ? t[i - k] : 0) + curMax * k);
            }
        }
        
        // for(int j=0;j<n;j++){
        //     cout<<t[j]<<" ";
        // }
        
        return t[n - 1];
     
    }
};
