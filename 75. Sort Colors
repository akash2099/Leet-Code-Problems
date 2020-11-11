class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // return nums;
        unordered_map<int,int>mp;
        mp[0]=0;
        mp[1]=0;
        mp[2]=0;
        
        for(int i=0;i<nums.size();++i){
            ++mp[nums[i]];
        }
        
        int c=0;
        for(int i=0;i<mp[0];++i){
            nums[c++]=0;
        }
        
        for(int i=0;i<mp[1];++i){
            nums[c++]=1;
        }
        
        for(int i=2;i<mp[2];++i){
            nums[c++]=2;
        }
    }
};
