static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int curr=n;
        
        vector<int>v;
        
        for(int i=0;i<n;++i){
            v.push_back(gas[i]-cost[i]);    
        }
        v.push_back(0);
        
        for(int i=n-1;i>=1;--i){
            if(v[i]>=0){
                v[i]+=v[curr];
                curr=i;
            }
            else{
                v[i-1]+=v[i];
            }
        }
        
        // for(int i=0;i<n;++i){
        //     cout<<v[i];    
        // }
        
        if(v[0]>=0)
            return 0;
        
        if(curr!=-n && (v[curr]+v[0]>=0))
            return curr;
        else
            return -1;       
        
        // return -1;
    }
};
