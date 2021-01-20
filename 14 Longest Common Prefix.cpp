static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        
        if(n==0)
            return ans;
        
        if(n==1)
            return strs[0];
        
        
        int i=0;
        int j=0;

        while(true){   
            
            // cout<<i<<" "<<j<<endl;
            
            if(j<strs[i].size() && j<strs[i+1].size()){
                char pre=strs[i][j];
                char curr=strs[i+1][j];

                if(curr==pre){
                    ++i;
                }
                else{
                    return ans;
                    // break;
                }

                if(i==n-1){
                    i=0;
                    ans.push_back(strs[0][j]);
                    ++j;
                }

            }
            else{
                return ans;
                // break;
            }
            
        }
        
        return ans;
    }
};
