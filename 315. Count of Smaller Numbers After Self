# define V vector<int>

# define VP vector<pair<int,int>>
// #define ppi pair<int,int>
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    // Modified merge sort for this kind of problem    
    /***** FROM GFG *****/
    // Merges two subarrays of arr[]. 
    // First subarray is arr[l..m] 
    // Second subarray is arr[m+1..r] 
    void merge(V &ans,VP &arr, int l, int m, int r) 
    { 
        int n1 = m - l + 1; 
        int n2 = r - m; 

        // Create temp arrays  
        VP L(n1),R(n2); 

        // Copy data to temp arrays L[] and R[]  
        for(int i = 0; i < n1; i++) 
            L[i] = arr[l + i]; 
        for(int j = 0; j < n2; j++) 
            R[j] = arr[m + 1 + j]; 

        // Merge the temp arrays back into arr[l..r] 

        // Initial index of first subarray 
        int i = 0;  

        // Initial index of second subarray 
        int j = 0;  

        // Initial index of merged subarray 
        int k = l; 

        int temp_count=0;
        
        while (i < n1 && j < n2) 
        { 
            if (L[i].first <= R[j].first)  
            { 
                arr[k] = L[i]; 
                ++i;
                if(temp_count>0 && i<n1){
                    // store index= arr[i] value's index,
                    ans[L[i].second]+=temp_count;
                }  
            } 
            else 
            { 
                arr[k] = R[j]; 
                ++temp_count;
                
                if(temp_count>0){
                    // store index= arr[i] value's index,
                    ans[L[i].second]+=1;
                }
                ++j;
            }    
            ++k; 
        }

        // Copy the remaining elements of 
        // L[], if there are any  
        while (i < n1)  
        { 
            arr[k] = L[i];
            ++i;
            if(temp_count>0 && i<n1){
                // store index= arr[i] value's index,  
                ans[L[i].second]+=temp_count;
            }            
            ++k; 
        } 

        // Copy the remaining elements of 
        // R[], if there are any  
        while (j < n2) 
        { 
            arr[k] = R[j]; 
            ++j; 
            ++k; 
        } 
    } 

    // l is for left index and r is  
    // right index of the sub-array 
    // of arr to be sorted */ 
    void mergeSort(V &ans,VP &arr, int l, int r) 
    { 
        if (l < r) 
        { 

            // Same as (l+r)/2, but avoids  
            // overflow for large l and h 
            int m = l + (r - l) / 2; 

            // Sort first and second halves 
            mergeSort(ans, arr, l, m); 
            mergeSort(ans, arr, m + 1, r); 
            merge(ans, arr, l, m, r); 
        } 
    } 

    vector<int> countSmaller(vector<int>& nums) {
       
        // Using Merge sort O(nlogn)
        V ans(nums.size(),0);
        VP arr(nums.size());            
           
        for(int i=0;i<nums.size();++i){
            arr[i]=make_pair(nums[i],i);
        }
        
        // for(int i=0;i<arr.size();++i){
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        // }
        
        // cout<<endl<<endl;
        
        // make arr as vector of pair, make_pair(nums[i],i)
        // then adjust arr in the above two functions
        
        mergeSort(ans,arr,0,nums.size()-1);
        
        // for(int i=0;i<arr.size();++i){
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        // }
        
        // cout<<endl;
        
        // for(int i=0;i<ans.size();++i){
        //     cout<<ans[i]<<" ";
        // }
        
        return ans;
        
        // Later try with other approach
    }
};
