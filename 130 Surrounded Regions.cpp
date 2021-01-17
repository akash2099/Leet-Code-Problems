static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        if(n==0)
            return;
        int m=board[0].size();
        if(m==0)
            return;
        
        // cout<<n<<m<<endl;
        
        vector<vector<int> > v( n , vector<int> (m, 0)); 
        stack<pair<int,int>>s;
        
        // For vertical columns first and last
        for(int i=0;i<n;++i){
            
            if(v[i][0]==0 && board[i][0]=='O'){  // board[i][0] // 1st column

                s.push(make_pair(i,0));

                while(!s.empty()){

                    int x=s.top().first;
                    int y=s.top().second;
                    s.pop();

                    v[x][y]=1;// visit

                    //move right
                    if(y+1<m && v[x][y+1]==0 && board[x][y+1]=='O')
                        s.push(make_pair(x,y+1));

                    // move down
                    if(x+1<n && v[x+1][y]==0 && board[x+1][y]=='O')
                        s.push(make_pair(x+1,y));

                    // move up
                    if(x-1>=0 && v[x-1][y]==0 && board[x-1][y]=='O')
                        s.push(make_pair(x-1,y));

                    // move left
                    if(y-1>=0 && v[x][y-1]==0 && board[x][y-1]=='O')
                        s.push(make_pair(x,y-1));

                }
                
            }
            
            if(m!=1){
                if(v[i][m-1]==0 && board[i][m-1]=='O'){ // board[i][m-1] // last column
                    
                    s.push(make_pair(i,m-1));

                    while(!s.empty()){

                        int x=s.top().first;
                        int y=s.top().second;
                        s.pop();

                        v[x][y]=1;// visit

                        //move right
                        if(y+1<m && v[x][y+1]==0 && board[x][y+1]=='O')
                            s.push(make_pair(x,y+1));

                        // move down
                        if(x+1<n && v[x+1][y]==0 && board[x+1][y]=='O')
                            s.push(make_pair(x+1,y));

                        // move up
                        if(x-1>=0 && v[x-1][y]==0 && board[x-1][y]=='O')
                            s.push(make_pair(x-1,y));

                        // move left
                        if(y-1>=0 && v[x][y-1]==0 && board[x][y-1]=='O')
                            s.push(make_pair(x,y-1));

                    }
                }
            }
            
            // do bfs on the above element, when found v[i][j]=1
            // cout<<i<<endl;
            // for(int p=0;p<n;++p){
            //     for(int q=0;q<m;++q){
            //         cout<<v[p][q]<<" ";
            //     }
            //     cout<<endl;
            // }

        }   
        
        // For horizontal rows first and last except first elements
        for(int j=1;j<m-1;++j){
            
            if(v[0][j]==0 && board[0][j]=='O'){  // board[0][j] // 1st row

                s.push(make_pair(0,j));

                while(!s.empty()){

                    int x=s.top().first;
                    int y=s.top().second;
                    s.pop();

                    v[x][y]=1;// visit

                    //move right
                    if(y+1<m && v[x][y+1]==0 && board[x][y+1]=='O')
                        s.push(make_pair(x,y+1));

                    // move down
                    if(x+1<n && v[x+1][y]==0 && board[x+1][y]=='O')
                        s.push(make_pair(x+1,y));

                    // move up
                    if(x-1>=0 && v[x-1][y]==0 && board[x-1][y]=='O')
                        s.push(make_pair(x-1,y));

                    // move left
                    if(y-1>=0 && v[x][y-1]==0 && board[x][y-1]=='O')
                        s.push(make_pair(x,y-1));
                }
                
            }
            
            if(n!=1){
                if(v[n-1][j]==0 && board[n-1][j]=='O'){ // board[n-1][j] // last row
                    
                    s.push(make_pair(n-1,j));

                    while(!s.empty()){

                        int x=s.top().first;
                        int y=s.top().second;
                        s.pop();

                        v[x][y]=1;// visit

                        //move right
                        if(y+1<m && v[x][y+1]==0 && board[x][y+1]=='O')
                            s.push(make_pair(x,y+1));

                        // move down
                        if(x+1<n && v[x+1][y]==0 && board[x+1][y]=='O')
                            s.push(make_pair(x+1,y));

                        // move up
                        if(x-1>=0 && v[x-1][y]==0 && board[x-1][y]=='O')
                            s.push(make_pair(x-1,y));

                        // move left
                        if(y-1>=0 && v[x][y-1]==0 && board[x][y-1]=='O')
                            s.push(make_pair(x,y-1));

                    }
                }
            }
            
            // do bfs on the above element, when found v[i][j]=1
            // cout<<j<<endl;
            // for(int p=0;p<n;++p){
            //     for(int q=0;q<m;++q){
            //         cout<<v[p][q]<<" ";
            //     }
            //     cout<<endl;
            // }
        }
        
        // cout<<endl;
        // for(int p=0;p<n;++p){
        //     for(int q=0;q<m;++q){
        //         cout<<v[p][q]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]=='O' && v[i][j]==0) // flip condition
                    board[i][j]='X';
            }
        }
    }
};
