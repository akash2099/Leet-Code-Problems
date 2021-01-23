static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
private:
    int n,m;
    int dfs(vector<vector<int>>& grid, int x, int y, int zero){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==-1) // condition which are not valid
            return 0; // no path
        
        if(grid[x][y]==2)
            return zero==-1?1:0; // 1 path found, and zero will decrease one more because of one extra last cell coverage
        
        grid[x][y]=-1; //take decision
        --zero;
        
        int totalPaths=dfs(grid,x+1,y,zero)+ // down
            dfs(grid,x-1,y,zero)+ // up
            dfs(grid,x,y+1,zero)+ // right
            dfs(grid,x,y-1,zero); // left
        
        grid[x][y]=0; // undo decision
        ++zero;
        
        return totalPaths;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0,si=0,sj=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==0)
                    ++zero;
                else if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
            }
        }
        return dfs(grid,si,sj,zero);
    }
};
