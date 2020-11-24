static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2)
            return 0;
        
        vector<int>maxl(n); // left max
        vector<int>maxr(n); // right max
        
        maxl[0]=height[0];
        for(int i=1;i<n;i++)
            maxl[i]=max(maxl[i-1],height[i]);
        
//         maxr[n-1]=height[n-1];
//         for(int i=n-2;i>=0;i--)
//             maxr[i]=max(maxr[i+1],height[i]);
        
//         int w=0; // water
//         for(int i=0;i<n;i++){
//             if(maxl[i])
//             w+=min(maxl[i],maxr[i])-height[i];
//         }
//         return w;

        
        int sum=0;
        maxr[n-1]=height[n-1];
        sum+=min(maxr[n-1],maxl[n-1])-height[n-1];
        for(int i=n-2;i>=0;i--){
            maxr[i]=max(maxr[i+1],height[i]);
            sum+=min(maxr[i],maxl[i])-height[i];
        }
        return sum;
        

    }
};
