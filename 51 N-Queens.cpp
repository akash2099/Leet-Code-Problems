static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    /*
    // My solution
    bool isValid(vector<int> cellPlacements){ // check validity of board, toughest part
        // you can use a for loop
        int row=cellPlacements.size()-1; // rowId
        for(int i=0;i<row;++i){
            int diff=abs(cellPlacements[i]-cellPlacements[row]);//abs(cp[i]-cp[n-1)])
            if(diff==0 || diff == (row-i)){ // same col || same diagonal
                return false;
            }
        }
        return true;
    }
    
    void doSolve(vector<int> &cellPlacements, int n, int row,vector<vector<int>>& result){
            if(row==n){ // complete
                result.push_back(cellPlacements); 
            }
            else{
                for(int j=0;j<n;++j){
                    // board[row][j]='Q'; // take decision
                    cellPlacements.push_back(j); // take decision at row
                    if(isValid(cellPlacements)){ // check validity
                        doSolve(cellPlacements,n,row+1,result); // resolve
                    }
                    // board[row][j]='.'; // undo decision
                    cellPlacements.pop_back(); // undo decision
                }
            }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<int> cellPlacements;
        vector<vector<int>> result;
        doSolve(cellPlacements,n,0,result);
        
        vector<vector<string>>ans;
        
        for(int i=0;i<result.size();++i){
            vector<string>temp_string;
            for(int j=0;j<n;++j){
                // cout<<result[i][j]<<" ";
                string temp="";
                for(int k=0;k<n;++k){
                    if(k==result[i][j])
                        temp+="Q";
                    else
                        temp+=".";
                }
                temp_string.push_back(temp);
            }
            // cout<<endl;
            ans.push_back(temp_string);
        }
        
        return ans;
        
    }
    */
    
    // More readable solution and bit straight forward
    vector<vector<string>> ans;
	
    bool isValid(vector<string> &s, int r, int c){
        for(int i=r;i>=0;i--)
            if(s[i][c]=='Q')
                return false;
        for(int i=r,j=c;i>=0 && j>=0;i--,j--)
            if(s[i][j]=='Q')
                return false;
        for(int i=r,j=c;i>=0 && j<s.size();i--,j++)
            if(s[i][j]=='Q')
                return false;
        return true;
    }

    void backtrack(vector<string> &s, int r){
        if(r==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(isValid(s,r,i)){
                s[r][i]='Q';
                backtrack(s,r+1);
                s[r][i]='.';
            }
        }
            
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n, string(n,'.'));// declare 2d vector
        ans.clear(); // for global var
        backtrack(s,0);
        return ans;
    }
    
};
