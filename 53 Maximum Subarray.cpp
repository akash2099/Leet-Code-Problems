static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

/*
// Recursion
int res;
void solve(vector<int> nums,int n,int sum){
    
    res=max(res,sum);
    
    // Invalid Input base case
    if(n==-1)
        return;
    
    //Hypothesis
    solve(nums,n-1,sum+nums[n]);
    solve(nums,n-1,nums[n]);

}

*/

// # define ll long long
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Recursion
        // if(nums.size()==0)
        //     return 0;
        // else if(nums.size()==1)
        //     return nums[0];
        // else
        //     // Recursion
        //     res=INT_MIN;
        //     solve(nums,nums.size()-2,nums[nums.size()-1]);
        //     return res;
        
        
        // 8ms
        int max_ans = nums[0]; 
        int cur = nums[0]; 

        for (int i = 1; i < nums.size(); i++) 
        { 
            cur = max(nums[i], cur+nums[i]); 
            max_ans = max(max_ans, cur); 
        } 
        return max_ans; 
        
        // idon't understand this ans
//         ll max_ans = nums[0]; 
//         ll cur =0; 

//         for (ll i = 0; i < nums.size(); i++) 
//         { 
//             cur += nums[i]; 
//             if(cur>max_ans)
//                 max_ans=cur;
            
//             if(cur<0)
//                 cur=0;
//         } 
//         return max_ans; 
       
    }
};
