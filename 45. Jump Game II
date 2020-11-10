// #define V vector<int>
// #define ppi pair<int,int>

static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        // DP time: O(n^2), space: O(n)
        int n=nums.size();

        V t(n,0);
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(i-j<=nums[j]){
                    if(t[i]==0){
                        t[i]=t[j]+1; // here you can also store the index j                        
                    }
                    else if(t[j]+1<t[i])
                        t[i]=t[j]+1;
                }
            }
        }
        
        // for(int i=0;i<n;++i)
        //     cout<<t[i];
        return t[n-1];
        */
        
        //time: O(n), space: O(1)
        // once we have reached the farthest index from one index, we should consider that
        int pos=0;
        int farthest=0;
        int jump=0;
        
        for(int i=0;i<nums.size()-1;++i){
            if(farthest<i+nums[i]) // calculate the farthest distance
                farthest=i+nums[i];
            
            if(pos==i){ // update the pos after reaching the last farthest position
                pos=farthest;
                ++jump;
            }
        }
        return jump;
    }
};
