static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    // calculate no of numbers smaller than mid in each row
    int countLessEqual(vector<vector<int>> matrix, int n, int num){
        int c=0;
        for(int i=0;i<n;i++){
            int l=0;
            int r=n;
            while(l<r){
                int m=l+(r-l)/2;
                
                if(matrix[i][m]<=num)
                    l=m+1;
                else
                    r=m;
            }
            c+=l;
        }
        return c;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        // Need to understand the code a bit
        
        // in discussion O(n) idk
        // using heap O(n^2logk) may be
        // Binary search better time complexity
        
        int n=matrix.size();
        if (n==0)
            return 0;
        int m=matrix[0].size();
        if (m==0)
            return 0;
        
        int left=matrix[0][0];
        int right=matrix[n-1][m-1];
        
        while(left<right){
            int mid=left+(right-left)/2;
            if(countLessEqual(matrix,n,mid)<k)
                left=mid+1;
            else
                right=mid;
        }
        
        return left; //ans
    }
};
