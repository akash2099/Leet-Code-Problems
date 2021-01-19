static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
/*
// My code
class Solution {
public:
    int help[200][200];
    int n=0;
    int m=0;
    int max_len=0;
    
    int findAns(int x,int y, vector<vector<int>> matrix){
    
        // if(help[x][y]!=-1) // redundant case
        //     return help[x][y];
        
        int right=0,down=0,up=0,left=0;
        
        //move right
        if(y+1<m && matrix[x][y]<matrix[x][y+1]){
            if(help[x][y+1]!=-1){
                right=help[x][y+1];
            }
            else{
                right=findAns(x,y+1,matrix);
            }
        }

        // move down
        if(x+1<n && matrix[x][y]<matrix[x+1][y]){
            if(help[x+1][y]!=-1){
                down=help[x+1][y];
            }
            else{
                down=findAns(x+1,y,matrix);
            }
        }

        // move up
        if(x-1>=0 && matrix[x][y]<matrix[x-1][y]){
            if(help[x-1][y]!=-1){
                up=help[x-1][y];
            }
            else{
                up=findAns(x-1,y,matrix);
            }
        }

        // move left
        if(y-1>=0 && matrix[x][y]<matrix[x][y-1]){
            if(help[x][y-1]!=-1){
                left=help[x][y-1];
            }
            else{
                left=findAns(x,y-1,matrix);
            }
        }
        
        int ans=max(right,max(down,max(up,left)))+1;
        
        if(ans>max_len) // store the max_length
            max_len=ans;

        // cout<<ans<<" "<<max_len<<" "<<x<<" "<<y<<endl;
        
        return help[x][y]=ans; // memorization
    
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        if(n==0)
            return 0;
        m=matrix[0].size();
        cout<<n<<" "<<m;
        max_len=0;
        
        memset(help,-1,sizeof(help));
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(help[i][j]==-1)
                    // cout<<i<<" "<<j<<"inside main"<<endl;
                    int x=findAns(i,j,matrix);//ignore x    
            }
        }
        return max_len;

    }
};

*/

class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> f;

    int DFS(vector<vector<int>>& M, int r, int c) {
        if (f[r][c] > 0) return f[r][c]; // retrieve
        int res = 1;
        if (r+1 < rows && M[r+1][c] > M[r][c]) res = max(res, 1 + DFS(M, r+1, c));
        if (r-1 >= 0   && M[r-1][c] > M[r][c]) res = max(res, 1 + DFS(M, r-1, c));
        if (c+1 < cols && M[r][c+1] > M[r][c]) res = max(res, 1 + DFS(M, r, c+1));
        if (c-1 >= 0   && M[r][c-1] > M[r][c]) res = max(res, 1 + DFS(M, r, c-1));
        f[r][c] = res; // save
        return f[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        rows = M.size();
        cols = M[0].size();
        f = vector<vector<int>>(rows, vector<int>(cols, 0));

        int res = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                res = max(res, DFS(M, r, c));
            }
        }
        return res;
    }
};
