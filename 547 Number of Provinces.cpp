static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    # define endl '\n'
    return 0;
}();
class Solution {
public:
    int visited[200]={0};
    void dfs(vector<vector<int>>& ic, int i,int m){
        visited[i]=1;
        for(int j=0;j<m;++j){
            if(ic[i][j]!=0 && visited[j]==0){
                dfs(ic,j,m);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // number of connected components, from adjacency matrix
        int n=isConnected.size();
        if(n==0)
            return 0;
        int m=isConnected[0].size();

        int ans=0;
        for(int i=0;i<n;++i){
            if(visited[i]==0){
                ++ans;
                dfs(isConnected,i,m);
            }
        }
        return ans;
    }
};
