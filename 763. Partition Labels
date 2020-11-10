#define ppi pair<int,int>
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        unordered_map<char,ppi>mp;
        
        for(int i=0;i<S.length();++i){
            auto itr=mp.find(S[i]);
            if(itr==mp.end()){
                pair<int,int>p;
                p.first=i;
                p.second=i;
                mp[S[i]]=p; 
            }
            else{
                ppi p=itr->second;
                p.second=i;
                mp[S[i]]=p;             
            }

        }
        
        vector<ppi>vans;
        
        for (auto itr = mp.begin(); itr != mp.end(); itr++) 
        { 
            // itr works as a pointer to pair<string, double> 
            // type itr->first stores the key part  and 
            // itr->second stroes the value part 
            
            // cout << itr->first <<" ";
            ppi pp=itr->second;
            // cout<<pp.first<<","<<pp.second<<endl;
            vans.insert(vans.begin(),pp);
        }
        
        vans.push_back(make_pair(S.length(),-1));
        
        sort(vans.begin(), vans.end());
        
        vector<int>v;
        int curr=vans[0].first;
        int mv=vans[0].second;
        
        for (int i=1;i<vans.size();i++) 
        { 
            ppi pp=vans[i];
            // cout<<pp.first<<","<<pp.second<<endl;
            
            if(pp.first>mv){
                v.push_back(pp.first-curr);
                curr=pp.first;
                mv=pp.second;
            }
            else{
                if(mv<pp.second)
                    mv=pp.second;
            }
        }
    

        return v;        
    }
};
