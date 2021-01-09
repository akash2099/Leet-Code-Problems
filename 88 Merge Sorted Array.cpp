static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
            return;
        // for inplace swap
        vector<int>v;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                ++i;
            }
            else{
                v.push_back(nums2[j]);
                ++j;
            }
        }
        
        while(i<m){
            v.push_back(nums1[i]);
            ++i;
        }
        
        while(j<n){
            v.push_back(nums2[j]);
            ++j;
        }
        
        nums1=v;
    }
};
