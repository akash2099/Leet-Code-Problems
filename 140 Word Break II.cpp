static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    unordered_map<string,vector<string>>mp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        if(mp.find(s)!=mp.end()) // Memorization
            return mp[s];
        
        vector<string>result;
        
        if(count(wordDict.begin(), wordDict.end(), s))
            result.push_back(s);
        
        for(int i=1;i<=s.length();++i){
            
            string curr=s.substr(0,i); // take decision, break word
            
            if(count(wordDict.begin(), wordDict.end(), curr)){ // if curr present, check validity
                vector<string> subList=wordBreak(s.substr(i), wordDict);// recursively solve for remaining string
                
                // process subList
                for(string sen:subList){ // undo, combine
                    result.push_back(curr+" "+sen);
                }
            }
        }
        
        return mp[s]=result; // Memorization
    }
};
