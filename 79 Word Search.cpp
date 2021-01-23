static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    
    // Main Solution: 
    // Important board should be passed with &
    int n,m;
    bool dfs(vector<vector<char>> &board, int i, int j, int count, string word){
        if(count==word.length()){ // word found complete
            return true;
        }
        
        if(i<0 || i>=n || j<0 ||j>=m || board[i][j]!=word[count]){ // if it breaks the board
            return false;
        }
        
        // backtracking principle
        char temp=board[i][j];
        board[i][j]=' ';// used
        ++count;
        bool found=dfs(board,i+1,j,count,word)
            || dfs(board,i-1,j,count,word)
            || dfs(board,i,j+1,count,word)
            || dfs(board,i,j-1,count,word);
        
        board[i][j]=temp; // reset, undo
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {

        n=board.size();
        if(n==0)
            return true;
        
        m=board[0].size();
        if (n==0 || m==0) return false;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==word[0] && dfs(board,i,j,0,word)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
