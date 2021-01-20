static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        //FROM COURSE SCHEDUKE I
        // create a graph and then check for cycle if there is cycle then false, else true
        // If true:
        // Topological sorting gives the order of task to be done in a directed graph
        
        // [i,j]   j->i
        
        // Kahn's Algorithm
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto &p: pre) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        // degree contains the indegre of each element
        
        vector<int>res;// final topological sorted order
        
        queue<int> q;
        
        for (int i = 0; i < n; i++)
            if (degree[i] == 0) q.push(i); // find the element with indegree 0
    
        while (!q.empty()) {
            int curr = q.front(); 
            q.pop(); 
            
            res.push_back(curr); // not needed here

            n--; // if this gets executed for all n nodes then all courses can be covered
            
            for (auto next: adj[curr]){ // reduce the indegree of all the elements of adj list pointed by curr
                // if (--degree[next] == 0) q.push(next);
                --degree[next];
                if(degree[next]==0)
                    q.push(next);
            }
        }
        
        vector<int>empty_vector;
        
        return (n == 0)?res:empty_vector;
        
    }
};
