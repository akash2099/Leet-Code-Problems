static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        
        int m=grid[0].size();
        
        if(m==0)
            return 0;
        
        int left,top;
        
        for(int i=1;i<n;i++){
           grid[i][0]+=grid[i-1][0];
        }
        
        for(int j=1;j<m;j++){
            grid[0][j]+=grid[0][j-1];
        }
        
        // for(i=0;i<n;i++){
        //     for(j=0;j<m;j++){
        //         cout<<grid[i][j];
        //     }
        // }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                left=grid[i-1][j];
                top=grid[i][j-1];
                grid[i][j]+=min(left,top);
            }
        }
        
        return grid[n-1][m-1];
        
    }
};
