static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<1){
            return 0;
        }
        
        int l=1;
        int i=1,j=0;
        
        while(i<n){
            if(nums[i]==nums[j]){
                ++i;
            }
            else{
                ++j;
                nums[j]=nums[i];
                ++l;
            }
        }
        
        return l;
    }
};
