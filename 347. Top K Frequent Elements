static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

# define ppi pair <int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int ki=nums[i];
            if(mp.find(ki)==mp.end()){
                mp[ki]=1;
            }
            else{
                ++mp[ki];
            }
        }
        
        priority_queue <ppi, vector<ppi>, greater<ppi>> minh;
        
        for (auto x : mp){
            // cout<<x.first<<" "<<x.second<<endl;

            minh.push(make_pair(x.second,x.first));
            if(minh.size()>k)
                minh.pop();
        }
        
        vector<int>v;
        while(minh.size()>0){
            v.push_back(minh.top().second);
            minh.pop();
        }

            
        return v;
    }
};
