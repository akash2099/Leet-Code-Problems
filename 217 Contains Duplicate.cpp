static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
    
        for(int i=0;i<nums.size();++i){            
            if(mp[nums[i]]==1)
                return true;
            ++mp[nums[i]];
        }
        
        return false;
    }
};
