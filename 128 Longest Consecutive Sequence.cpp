static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>hs;
        for(int num: nums)
            hs.insert(num);
        
        int l=0;
        
        for(int num:nums){
            if(!hs.count(num-1)){ // count returns 1 or 0
                int curr=num;
                int cl=1;
                
                while(hs.count(curr+1)){
                    ++curr;
                    ++cl;
                }
                
                l=max(l,cl);
            }
        }
        
        return l;
        // Time : O(3*N)
    }
};
