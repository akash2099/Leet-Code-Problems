static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int firstUniqChar(string s) {
        int ar[26]={0};
        int index=-1;
        
        for(int i=0;i<s.length();++i){
            ++ar[s[i]-'a'];
        }
        
        for(int i=0;i<s.length();++i){
            if(ar[s[i]-'a']==1)
                return i;
        }
        
        return index;
    }
};
