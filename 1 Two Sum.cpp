static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        int n=nums.size();
        int i=0,j=n-1;
        
        // store in pairand the sort the pair with resepect to the first then do accordingkly fuck off
        unordered_map<int,in>mp; // pair
        for(int k=0;k<n;k++){
            mp[nums[k]]=k; // unique since only one answer is present 
        }
        
        sort(nums.begin(),nums.end()); // O(nlogn), need to sort for finding pair sum
        
        
        while(i<j){
            
            int value=nums[i]+nums[j]; // current pair sum
            
            if(value==target){
                return {mp[nums[i]].second,mp[nums[j]].second}; // since there is exactly one output
                // ++i;
                // --j;
            }
            else if(value>target){
                --j;
            }
            else{
                ++i;
            }
        }
        return {};
        */
        
        // Understand this solution
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];

                //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                        //+1 because indices are NOT zero based
                result.push_back(hash[numberToFind]);
                result.push_back(i);			
                return result;
            }

                //number was not found. Put it in the map.
            hash[nums[i]] = i;
        }
        return result;
    }
};
