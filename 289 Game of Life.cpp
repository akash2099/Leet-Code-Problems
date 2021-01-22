static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int validate_index(int i,int j,int n,int m,vector<vector<int>> &board){ // you can't send a pass by reference to pass by value
        if(i>=0 && i<n && j>=0 && j<m){
            if(board[i][j]==1 || board[i][j]==-1) // check live
                return true;          
        }
        
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        if(n==0)return;
        int m=board[0].size(); // remember this error
        
        // cout<<n<<m;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int live_cells=0;
                
                if(validate_index(i,j+1,n,m,board)) // right
                    ++live_cells;
                
                if(validate_index(i,j-1,n,m,board)) // left 
                    ++live_cells;
                
                if(validate_index(i+1,j,n,m,board)) // down
                    ++live_cells;
                
                if(validate_index(i-1,j,n,m,board)) // up
                    ++live_cells;
                
                if(validate_index(i+1,j+1,n,m,board)) // right-down
                    ++live_cells;
                
                if(validate_index(i-1,j+1,n,m,board)) // right-up
                    ++live_cells;
                
                if(validate_index(i-1,j-1,n,m,board)) // left-up
                    ++live_cells;
                
                if(validate_index(i+1,j-1,n,m,board)) // left-down
                    ++live_cells;
                
                // cout<<i<<" "<<j<<" "<<live_cells<<endl;
                
                if(board[i][j]==1 || board[i][j]==-1){ // current cell is live
                    if(live_cells<2 || live_cells>3){
                        board[i][j]=-1;// -1 means currently 1 but later 0    
                    }
                }
                else{   // already dead
                    if(live_cells==3)
                        board[i][j]=-2;// -2 means currently 0 but later 1
                }
                    
            }
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==-1)
                    board[i][j]=0;
                
                if(board[i][j]==-2)
                    board[i][j]=1;
            }
        }
        
    }
};
