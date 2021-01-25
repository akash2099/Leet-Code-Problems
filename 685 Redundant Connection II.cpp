/*
This problem is limited to a graph with N nodes and N edges. No node is singled out if a edge is removed. For example, [[1,2],[2,4],[3,4]], 4 nodes 3 edges, is not applicable to this problem. You cannot remove [3,4] to single out node 3.

There are 3 cases:

- No loop, but there is one node who has 2 parents.
- A loop, and there is one node who has 2 parents, that node must be inside the loop.
- A loop, and every node has only 1 parent.

**Case 1:** e.g. [[1,2],[1,3],[2,3]] ,node 3 has 2 parents ([1,3] and [2,3]). Return the edge that occurs last that is, return [2,3].
**Case 2:** e.g. [[1,2],[2,3],[3,1],[4,1]] , {1->2->3->1} is a loop, node 1 has 2 parents ([4,1] and [3,1]). Return the edge that is inside the loop, that is, return [3,1].
**Case 3:** e.g. [[1,2],[2,3],[3,1],[1,4]] , {1->2->3->1} is a loop, you can remove any edge in a loop, the graph is still valid. Thus, return the one that occurs last, that is, return [3,1].
*/

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
                // ................CASE CREAETION...............
                candA = {parent[edge[1]], edge[1]}; // higher priority as because it is present earlier, if cycle found this will be possible answer
                candB = edge; // found later so will be answer if canB not an answer
            }
        } 
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (candB == edge) continue; //...........CASE 1 PART 1........................
            // ABOVE, for this edges there is more than 1 parent, because we need to return last occurence so we first check the cycle
            
            int a = edge[0], b = edge[1], fa = root(parent, a),fb=root(parent,b);
            // Now every node only has 1 parent, so we only need to check cycle using DSU
            if (fa == fb) {
                if (candA.empty()) return edge; //.............CASE 3.................
                // candB=edge
                return candA; //.............CASE 2.................
            }
            
            parent[fb] = fa; 
        }
        return candB; //edge //...........CASE 1 PART 2........................
    }
private:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) 
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};
