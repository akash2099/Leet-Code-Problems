static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end()); // O(nlogn), need to sort for finding pair sum
        
        // From Youtube Video
        //Idea is to find the pair sum after fixing one index, remove duplicacy in between, via if-else better condition
        
        vector<vector<int>>ans;
        
        for(int i=0;i<n-2;++i){ // since atleast we need to leave last two indices, that will take care of overflow
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){// take care of duplicates
                
                int low=i+1;// start processing from i+1
                int high=n-1;// to last n-1
                int sum=0-nums[i]; // target_sum-nums[i]
                
                while(low<high){
                    
                    int value=nums[low]+nums[high]; // current pair sum
                    
                    if(value==sum){
                        // vector<int>temp={nums[i],nums[low],nums[high]};
                        ans.push_back({nums[i],nums[low],nums[high]});
                        
                        while(low<high && nums[low]==nums[low+1])++low;// remove duplicates within the range of low
                        while(low<high && nums[high]==nums[high-1])--high;// remove duplicates within the range of high
                        
                        // finally to reach the correct position
                        ++low;
                        --high;
                    }
                    else if(value>sum){ // decrease the right pointer
                        --high;
                    }
                    else{ // increase the left pointer
                        ++low;
                    }
                }
            }
        }
        
        return ans;
        
    }
};
