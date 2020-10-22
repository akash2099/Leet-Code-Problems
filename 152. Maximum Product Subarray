static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        if (n==0)
            return 0;
        
        //O(n) sol
        int ans=nums[0];
        int n1=1,n2=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                n1*=nums[i];
                n2*=nums[i];
                ans=max(ans,max(n1,n2));
            }
            else if(nums[i]<0){
                n1=1;
                n2*=nums[i];
                ans=max(ans,n2);
            }
            else{
                n1=1;
                n2=1;
                ans=max(ans,0);
            }
        }
        reverse(nums.begin(), nums.end());
        int ans1=nums[0];
        n1=1,n2=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                n1*=nums[i];
                n2*=nums[i];
                ans1=max(ans1,max(n1,n2));
            }
            else if(nums[i]<0){
                n1=1;
                n2*=nums[i];
                ans1=max(ans1,n2);
            }
            else{
                n1=1;
                n2=1;
                ans1=max(ans1,0);
            }
        }
        
        
    
        return max(ans,ans1);
        
        // O(n^2)
//         int k=1;
//         long long ans=nums[0];
//         long long tem=1;
//         for(int i=1;i<n;i++){
//             k=1;
//             tem=nums[i];
//             ans=max(ans,tem);
//             while((i-k)>=0){
//                 tem*=nums[i-k];
//                 ans=max(ans,tem);
//                 ++k;
//             }
//         }
        
//         return ans;
        
        
        
    }
};
