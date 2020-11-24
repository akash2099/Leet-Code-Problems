static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int total_sum=0;
        int n=nums.size();
        if(n==0)
            return 0;
        
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        
       
        
        int target_sum=0;
        if((total_sum%2!=0 && S%2==0)||(total_sum%2==0 && S%2!=0))
            return 0;
        else
            target_sum=(total_sum/2)-(S/2);
        
        
        if(target_sum<0)
            return 0;
        
        
        int no_of_zeros_value=1;
        int t[n+1][target_sum+1];
        
        // A bit different initialization
        for(int i=0;i<n+1;i++){
            if(i!=0){
                if(nums[i-1]==0)
                    no_of_zeros_value*=2;
                
                t[i][0]=no_of_zeros_value;
            }
            else{
                t[i][0]=1;
            }
        }
        
        for(int j=1;j<target_sum+1;j++){
            t[0][j]=0;
        }
        
        
        // Same as knapsack
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target_sum+1;j++){
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        
        return t[n][target_sum];
        
        
    }
};
