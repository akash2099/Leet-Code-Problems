static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n==0||m==0)
            return 0;        
        
        int arr[m][n];
        int left,top;
        
        for(int i=1;i<m;i++){
           arr[i][0]=1;
        }
        
        for(int j=1;j<n;j++){
            arr[0][j]=1;
        }
        
        // for(i=0;i<m;i++){
        //     for(j=0;j<n;j++){
        //         cout<<arr[i][j];
        //     }
        // }
    
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                left=arr[i-1][j];
                top=arr[i][j-1];
                arr[i][j]=left+top;
            }
        }
        
        return arr[m-1][n-1];
    }
};
