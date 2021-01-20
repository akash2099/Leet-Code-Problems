static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    /*
    // if a node is connected to its ancestor and also present in the recursionStack, then it contains cycle
    int n;
    vector<int>vis;
    vector<int>recStack;

    bool dfs(int v,int par, vector<vector<int>>ar){
        vis[v]=1;// visit
        recStack[v]=1;// add to recStack
        for(int i=0;i<ar[v].size();++i){
            int child=ar[v][i];
            if(vis[child]==0){// if not visited
                if(dfs(child,v,ar)==true)// contains backedge in child
                    return true;
            }// backedge condition ,else if(child!=par) for undirected graph
            else if(recStack[child]){ // if visited but also must be present in recStack
                return true;
            }
        }
        recStack[v]=0;//remove from recStack
        return false; // no cycle
    }
    */
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        // Kahn's Algorithm
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto &p: pre) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        // degree contains the indegre of each element
        
        // vector<int>res;// final topological sorted order
        
        queue<int> q;
        
        for (int i = 0; i < n; i++)
            if (degree[i] == 0) q.push(i); // find the element with indegree 0
    
        while (!q.empty()) {
            int curr = q.front(); 
            q.pop(); 
            
            // res.push_back(curr); // not needed here

            n--; // if this gets executed for all n nodes then all courses can be covered
            
            for (auto next: adj[curr]){ // reduce the indegree of all the elements of adj list pointed by curr
                // if (--degree[next] == 0) q.push(next);
                --degree[next];
                if(degree[next]==0)
                    q.push(next);
            }
        }
        
        return n == 0;
        
        
        // create a graph and then check for cycle if there is cycle then false, else true
        
        // [i,j]   j->i
        /*
        int n=prerequisites.size();
        if(n==0)
            return true;
        
        
        // cout<<n;
        unordered_set <int> nodeSet ; 
  
        // creating adjacency list
        vector<vector<int>> ar(numCourses);

        for(int i=0;i<n;++i){
            ar[prerequisites[i][1]].push_back(prerequisites[i][0]); // directed
            nodeSet.insert(prerequisites[i][0]);
            nodeSet.insert(prerequisites[i][1]);
        }
        
        */
        
        // for(int i=0;i<ar.size();++i){
        //     cout<<endl<<i<<" ";
        //     for(int j=0;j<ar[i].size();++j){
        //         cout<<ar[i][j]<<" ....";
        //     }
        // }
        
        /*
        // visited array
        for(int i=0;i<numCourses;++i){
            vis.push_back(0);
            recStack.push_back(0);

        }
        
        // cout<<endl;
        // for(int i=0;i<numCourses;++i){
        //     cout<<vis[i]<<" rS "<<recStack[i];
        //     cout<<endl;
        // }
        
        // for disconnected components, with optimization
        for (auto itr = nodeSet.begin(); itr != nodeSet.end(); itr++) {
            if (!vis[*itr] && dfs(*itr,-1,ar)==true)
                return false;
        }
        
        // for(int i=0;i<numCourses;++i){
        //     if (!vis[i] && dfs(i,-1,ar)==true)
        //         return false;
        // }
        
        return true;
        // Topological sorting gives the order of task to be done in a directed graph
        */
        

        // BETTER APPROACH AVOID COMPILER RECURSION STACK

        
//         vector<int>vis(numCourses,0);
//         vector<int>recStack(numCourses,0);
//         vector<int>helper(numCourses,0);

//         stack<pair<int,int>>s;
//         // start dfs fromm node i
        
//         for (auto itr = nodeSet.begin(); itr != nodeSet.end(); itr++) {
            
//             if(!vis[*itr]){
//                 s.push({*itr,-1});
//                 // insert pair in stack{node,par}, 
//                 while(!s.empty()){
//                     int ele=s.top().first;
//                     int par=s.top().second;
//                     s.pop();
                
//                     if(vis[ele]==0){
//                         vis[ele]=1;
//                         recStack[ele]=1;
//                         for(int i=0;i<ar[ele].size();++i){
//                             int child=ar[ele][i];
//                             s.push({child,ele});
//                             ++helper[ele];
//                         }
//                     }
//                     else if(recStack[ele]){
//                         return false;// cycle found true
//                     }
                    
//                     if(par!=-1){
//                         --helper[par];
//                         if(helper[par]==0)
//                             recStack[ele]=0;
//                     }
//                 }
//             }
//         }
        
//         return true;// cycle not found
        
    }
};
