static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int t[m][n];
        memset(t,0,sizeof(t));
        for(int i=0;i<m;i++){
            t[i][0]=matrix[i][0];
        }
        
        for(int j=0;j<n;j++){
            t[0][j]=matrix[0][j];

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
                if(matrix[i][j]==1)
                    t[i][j]=1+min(t[i-1][j-1],min(t[i-1][j],t[i][j-1]));
            }
        }
        
        //[[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]
        cout<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<t[i][j]<<" ";
            } 
            cout<<endl;

        }
        
        long long sum=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+=t[i][j];
            } 
        }
        
        return sum;
  
    }
};
