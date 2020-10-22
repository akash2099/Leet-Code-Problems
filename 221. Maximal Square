static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
   int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size();
        if (n==0)
            return 0;
        
        int t[m][n];
        memset(t,0,sizeof(t));
        
        int ans=0;// initializing to 0 minimum

        for(int i=0;i<m;i++){
            t[i][0]=matrix[i][0]-'0';
            ans=max(ans,t[i][0]);
        }
        
        for(int j=0;j<n;j++){
            t[0][j]=matrix[0][j]-'0';
            ans=max(ans,t[0][j]);
        }
        
          
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<t[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                // considering t[i][j] is the bottom right corner for a square box
                if(matrix[i][j]=='1')
                    t[i][j]=1+min(t[i-1][j-1],min(t[i-1][j],t[i][j-1]));

                
                ans=max(ans,t[i][j]);
            }
        }
        // cout<<ans;
        
        return ans*ans;
    }
};
