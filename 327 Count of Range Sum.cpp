static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // # define endl '\n'
    return 0;
}();
// Using merge sort, Divide and conquer approach
class Solution {
public:
    void merge(vector<long>& sum, int lo1, int hi1, int lo2, int hi2) { // merge function normal
        // long[] helper = new long[hi2 - lo1 + 1];
        vector<int>helper(hi2 - lo1 + 1);
        int index = 0;
        int index1 = lo1, index2 = lo2;
        
        while (index1 <= hi1 && index2 <= hi2) {
            if (sum[index1] <= sum[index2]) {
                helper[index++] = sum[index1++];
            } else {
                helper[index++] = sum[index2++];
            }
        }
        
        while (index1 <= hi1) {
            helper[index++] = sum[index1++];
        }
        
        while (index2 <= hi2) {
            helper[index++] = sum[index2++];
        }
        
        
        // System.arraycopy(helper, 0, sum, lo1, hi2 - lo1 + 1);
        
//         for(int i=0;i<hi2-lo1+1;++i){
//             sum[i+lo1]=helper[i];    
//         }
        
        copy(begin(helper), end(helper), begin(sum) + lo1); // inbuilt copy function
        
    }
    
    int mergeSort(vector<long>& sum, int lo, int hi, int lower, int upper) { // modified mergeSort
        
        if (lo >= hi) return 0;// invalid
        int mid = (hi + 1 - lo) / 2 + lo; // hi+1 here as we dont want the index to go negative
        
        int count = mergeSort(sum, lo, mid - 1, lower, upper) + 
            mergeSort(sum, mid, hi, lower, upper); // recursively find ans
        
        // Main algorithm
        int startIndex = mid, endIndex = mid;
        
        for (int i = lo; i < mid; i++) {
            // go to least valid index = startIndex
            while (startIndex <= hi && sum[startIndex] - sum[i] < lower) {
                startIndex++;
            }
            
            // go to least upper invalid index = endIndex
            while (endIndex <= hi && sum[endIndex] - sum[i] <= upper) {
                endIndex++;
            }
            
            count += endIndex - startIndex;
        }
        
        // before merge compute the count as after that relative order will be disturbed
        merge(sum, lo, mid - 1, mid, hi);
        return count;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        
        return mergeSort(sum, 0, n, lower, upper); // sum range between [lower,upper]
    }
};
