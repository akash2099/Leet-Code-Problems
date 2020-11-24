static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // word1->col size
        //word2->row size
        
        int dp[m+1][n+1];
        // for i-> i deletion word1->word2=""
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        
        // for j-> j insertion word1=""->word2
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];// do nothing
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;// minimum of replace,delete,insert
                }
            }
        }
        return dp[m][n];
        
        // Explanation:
        // https://youtu.be/MiqoA-yF-0M
    }
};
