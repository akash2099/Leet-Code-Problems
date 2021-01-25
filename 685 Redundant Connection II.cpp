static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    # define endl '\n'
    return 0;
}();
// preety tough
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB; // here parent is the direct parent of that node initiially after the below loop
        // step 1, check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0]; 
            else {
                candA = {parent[edge[1]], edge[1]}; // higher priority as because it is present earlier, if cycle found this will be possible answer
                candB = edge; // found later so will be answer if canB not an answer
            }
        } 
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (candB == edge) continue; // for this edges there is more than 1 parent, because we need to return last occurence so we first check the cycle
            
            int a = edge[0], b = edge[1], fa = root(parent, a),fb=root(parent,b);
            // Now every node only has 1 parent, so we only need to check cycle using DSU
            if (fa == fb) {
                if (candA.empty()) return edge;// candB=edge
                return candA;
            }
            
            parent[fb] = fa; 
        }
        return candB; //edge
    }
private:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) 
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};
