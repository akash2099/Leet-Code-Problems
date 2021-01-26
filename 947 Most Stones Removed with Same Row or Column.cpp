/*
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    // union by rank and find with path compression
    int find(int a, vector<int>& par){
        if(par[a]==a)
            return a;
        return par[a]=find(par[a],par);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
                
        vector<int>par(n); 
        vector<int>rank(n); 
        int count=n;
        for(int i=0;i<n;++i) par[i]=i,rank[i]=1;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    // merge i, j
                    int fa=find(i,par);
                    int fb=find(j,par);
                    if(fa!=fb){
                        if(rank[fa]>rank[fb]){
                            par[fb]=fa;
                            rank[fa]+=rank[fb];
                        }
                        else{
                            par[fa]=fb;
                            rank[fb]+=rank[fa];
                        }
                        --count;
                        // cout<<i<<" "<<j<<endl;;
                    }
                }
            }
        }
        // cout<<count;
        return n-count; // total no of st0ones - no of cc, only via horizonatal or vertical

    }
};
*/
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
struct dsu {
    vector<int> parent;
    vector<int> size;
    int components = 0;
 
    dsu(int n = -1) {
        if (n >= 0)
            init(n);
    }
    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int get(int x) {
        return x == parent[x] ? x : parent[x] = get(parent[x]);
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return false;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};
 
class Solution {
public:
    int removeStones(vector<vector<int>>& a) {
        int mx = -1 ;
        int n = a.size() ;
        for(auto it : a) for(int x : it) mx = max(mx, x) ;
        mx++ ;
        // cout<<mx;
        dsu d(mx+mx) ;
        for(auto it : a){
            d.unite(it[0], it[1]+mx) ; // make sure no overlapping occurs
        }
        
        set<int> st ;
        for(auto x : a) st.insert(d.get(x[0])) ; // considering only those which are present in the input
        return n-(int)st.size() ;

        
//         int ans=0;
        
//         for(int i=0;i<mx+mx;++i){
//             if(d.get(i)==i)
//                 ++ans;
//         }
//         return n-ans ;
        
    }
};
