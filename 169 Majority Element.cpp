static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int major=nums[0];

        // This algorithm works  because there are atleast one majority element with more than n/2 number of occurences
        for(int i=1;i<nums.size();++i){
            if(nums[i]==major)
                ++count;
            else
                --count;
            
            if(count==0){
                major=nums[i];
                ++count;
            }
            // cout<<count;
        }
        
        return major;
    }   
};
