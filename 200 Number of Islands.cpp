static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size();
        
        stack<pair<int,int>>s;
        int count=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){ // not visited, once visited or not land grid[i][j]="0"
                    ++count;// also increment count of islands
                    // cout<<i<<" "<<j<<endl;
                    s.push(make_pair(i,j));

                    while(!s.empty()){
                        
                        int x=s.top().first;
                        int y=s.top().second;
                        s.pop();
                        
                        grid[x][y]='0';// visit

                        //move right
                        if(y+1<m && grid[x][y+1]=='1')
                            s.push(make_pair(x,y+1));
                        
                        // move down
                        if(x+1<n && grid[x+1][y]=='1')
                            s.push(make_pair(x+1,y));
                        
                        // move up
                        if(x-1>=0 && grid[x-1][y]=='1')
                            s.push(make_pair(x-1,y));
                        
                        // move left
                        if(y-1>=0 && grid[x][y-1]=='1')
                            s.push(make_pair(x,y-1));
    
                    }
                    
                    
                    // for(int k=0;k<n;++k){
                    // for(int l=0;l<m;++l)
                    //     cout<<grid[k][l]<<" ";
                    //     cout<<endl;
                    // }
                }
            }
        }
        
        return count;
    }
};
