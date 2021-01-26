static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // # define endl '\n'
    return 0;
}();

struct dsu {
    vector<int> root; //parent
    int count = 0;
 
    dsu(int n = -1) {
        if (n >= 0)
            init(n);
    }
    
    void init(int n) {
        root.resize((n + 1) * (n + 1));
        count  = 1;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                int num = i * (n + 1) + j; // convert the 2d to 1d array
                if (i == 0 || j == 0 || i == n || j == n) {
                    root[num] = 0; // important as only if the edges touch the boundary, then only partition will occur, tricky part
                }
                else {
                    root[num] = num;
                }
            }
        }
    }
    
    int find(int x) {
        if (root[x] != x) {
                root[x] = find(root[x]);
            }
            
        return root[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
            
        if (rootX == rootY) {
            ++count; // if they belong under same parent
            return;
        }

        root[rootY] = rootX;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        dsu d(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                char c = grid[i][j];
                
                if (c == '/'){
                    int x = i * (n + 1) + j + 1; // check the below left column charcter
                    int y = (i + 1) * (n + 1) + j;   
                    
                    d.unite(x, y);
                }
                else if (c == '\\'){
                    int x = i * (n + 1) + j; // check the below right column character
                    int y = (i + 1) * (n + 1) + j + 1;
                    
                    d.unite(x, y);
                }
            }
        }
        
        return d.count;
    }
};
