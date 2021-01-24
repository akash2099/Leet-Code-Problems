static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    # define endl '\n'
    return 0;
}();
class Solution {
public:
    double dfs(string start, string end, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited){
        if(graph.find(start) == graph.end()){
            return -1;
        }
        
        if(graph[start].find(end) != graph[start].end()){
            return graph[start][end];
        }
        
        for(const auto& nei : graph[start]){
            if(find(visited.begin(), visited.end(), nei.first) != visited.end())
                continue;
            visited.insert(nei.first);
            double res;
            if((res = dfs(nei.first, end, graph, visited)) != -1){
                //optimization: runtime 4ms -> 0ms
                return graph[start][end] = graph[start][nei.first] * res;
            }
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> quot;
        
        int N = equations.size();
        
        for(int i = 0; i < N; i++){
            const vector<string>& equation = equations[i];
            const string& num = equation[0], den = equation[1];
            const double& value = values[i];
            quot[num][num] = 1.0;
            quot[den][den] = 1.0;
            quot[num][den] = value;
            quot[den][num] = 1.0/value;
        }
        
        vector<double> ans;
        unordered_set<string> visited;
        
        for(const vector<string>& query : queries){
            const string& num = query[0], den = query[1];
            visited = {num};
            ans.push_back(dfs(num, den, quot, visited));
        }
        
        return ans;
    }
};
