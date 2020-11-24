static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 1,4 covered in swap sort
        // 2,3 will be covered in Math Algo not implementing right now, for one duplicate only
        // n*(n+1)/2-sum(nums[i])->eq1, difference of sum of squares->e2, solve both to get the ans,
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            else
                ++i;
        }
        
        vector<int>v;//duplicate numbers
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=i+1){
                // i+1->missing
                // nums[i]->duplicate
                v.push_back(nums[i]);
            }
        }
        
        return v[0];
    }
};
