static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return;
        
        int i=0,j;
       
        // computation will start after getting the first 0
        while(i<n){
            if(nums[i]==0)
                break;
            ++i;
        }
        
        j=i+1;
        
        while(i<n && j<n){
            
            if(nums[i]==0 && nums[j]!=0){
                // swap
                // int t=nums[i];
                // nums[i]=nums[j];
                // nums[j]=t;
                swap(nums[i],nums[j]);
            
                ++i;
                ++j;
            }
            
            if(j<n && nums[j]==0)
                ++j;
            
            if(i<n && nums[i]!=0)
                ++i;
        }
    }
};
