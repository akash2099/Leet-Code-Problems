// #define ppi pair<int,int>
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals;
        
        vector<vector<int>> v;
        // sort the intervals vector according to first
        vector<pair<int,int>>tem;
        for(int i=0;i<intervals.size();++i){
            tem.push_back(make_pair(intervals[i][0],intervals[i][1]));
        }
        
        sort(tem.begin(),tem.end());
        
        vector<int>t{tem[0].first,tem[0].second};
        v.push_back(t);
        
        for(int i=1,j=1;i<tem.size();++i){
            
            if(v[j-1][0]<=tem[i].first && tem[i].first<=v[j-1][1]){  // small(x-1)<=x<=large(x-1), 
                vector<int>t{v[j-1][0],max(v[j-1][1],tem[i].second)};
                v.erase(v.end()-1);
                v.push_back(t);
            }
            else{
                vector<int>t{tem[i].first,tem[i].second};
                v.push_back(t);
                ++j;
            }
        }
        return v;
    }
};
