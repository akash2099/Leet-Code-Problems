static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    # define endl '\n'
    return 0;
}();

class Solution {
public:
    int find(int a, vector<int>& par){
        if(par[a]==a)
            return a;
        return par[a]=find(par[a],par);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        vector<int>par;
        for(int i=0;i<=n;++i){
            par.push_back(i);
        }
        
        for(int i=0;i<n;++i){
            int a=edges[i][0];
            int b=edges[i][1];
            int fa=find(a,par);
            int fb=find(b,par);
            
            if(fa==fb){
                if(a>b)
                    return {b,a};
                return {a,b};
            }
            else{
                par[fa]=fb;
            }
        }
        return {edges[edges.size()-1][0],edges[edges.size()-1][1]};
        
    }
};
