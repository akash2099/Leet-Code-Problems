static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    void backtrack(vector<vector<int>> &res,vector<int> nums,vector<int> curr, vector<bool> visited){
        // base condition
        
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }
        
        // simple backtracking

        for(int i=0;i<nums.size();++i){
            if(visited[i]==true)
                continue;

            curr.push_back(nums[i]);
            visited[i] = true;
            backtrack(res,nums, curr,visited);
            
            curr.pop_back();
            visited[i] = false;
        } 
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<bool>visited(nums.size()); // by default false may be
        vector<int>curr;
        backtrack(res, nums,curr,visited);
        return res;
    }
};
/*
https://youtu.be/R3Sm9V2OSCo
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
         boolean[] visited = new boolean[nums.length];
         backtrack(res ,nums,new ArrayList(),visited);
         return res;
    }
    
     void backtrack(List<List<Integer>> res,int[] nums,List<Integer> curr, boolean[] visited){
                if(curr.size()==nums.length){
                 res.add(new ArrayList(curr));
                    return;
                }

                for(int i=0;i<nums.length;i++){
                    if(visited[i]==true)continue;
                    curr.add(nums[i]);
                    visited[i] = true;
                    backtrack(res,nums, curr,visited);
                    curr.remove(curr.size()-1);
                    visited[i] = false;
                } 
    }
}
*/
