static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //O(nlogk)
        
        priority_queue <int, vector<int>, greater<int>> minh;
        
        for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
            if(minh.size()>k)
                minh.pop();
        }
        
        return minh.top();
       
    }
};
