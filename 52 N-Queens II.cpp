static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int count=0;
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
            ++count;
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
    
    int totalNQueens(int n) {
        vector<string> s(n, string(n,'.'));// declare 2d vector
        count=0;
        backtrack(s,0);
        return count;
    }
};
