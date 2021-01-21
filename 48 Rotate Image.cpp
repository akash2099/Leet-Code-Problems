static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    
        // i1=j;
        // j1=n-(i+1); // +1 is for zero based indexing to 1 based indexing
        
        int n=matrix.size();
        if(n==1)
            return;
        
        // Time : k+k-2+k-4+....=m*k - (2+4+8+..)
        
        // Time: 3+n-(n-1)*log2(n-1)
        // Space: O(1)
        // always 3 swaps
        --n;
        int i=0;
        int r1=0;
        int r2=n-1;
        while(r1<=r2){
            for(int j=r1;j<=r2;++j){
                
                int a=matrix[i][j]; 
    
                matrix[i][j]=matrix[n-j][i]; // 0`
                matrix[n-j][i]=matrix[n-i][n-j]; // 270`
                matrix[n-i][n-j]=matrix[j][n-i]; // 180`
                matrix[j][n-i]=a; // 90`

            }
            
            ++i;
            ++r1;
            --r2;
        }        
    }
};
