static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
/*
int LCS(string s,string t,int n,int m){
    if(n==0||m==0)
        return 0;
    if(s[n-1]==t[m-1]){
        return 1+LCS(s,t,n-1,m-1);
    }
    else{
        return max(LCS(s,t,n,m-1),LCS(s,t,n-1,m));
    }
}
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        /*
        // TDBU
        int s_size=s.length();
        int t_size=t.length();
        
        int an[s_size+1][t_size+1];
        
        if (s==""){
            return true;
        }
        
        //Initialization
        for(int i=0;i<s_size;i++){
            for(int j=0;j<t_size;j++){
                if (i==0 || j==0)
                    an[i][j]=0;
            }
        }
        
        //Main code
        for(int i=1;i<=s_size;i++){
            for(int j=1;j<=t_size;j++){
                if(s[i-1]==t[j-1]){
                    an[i][j]=1+an[i-1][j-1];
                }
                else{
                    an[i][j] = max(an[i][j-1],an[i-1][j]);
                }
            }
        }
        */
        
        
        // Recursion
        // if(LCS(s,t,s_size,t_size)==s_size)
        //     return true;
        // else
        //     return false;
        
        // TDBU
        // if(an[s_size][t_size]==s_size)
        //     return true;
        // else
        //     return false;
        
        
        if(t.length() == 0){
            if(s.length() == 0){
                return true;
            }
            return false;
        }
        
        int i = 0, j = 0;
        while(i<s.length() && j<t.length()){
            if(s[i] == t[j]){
                i++; j++;
            } else {
                j++;
            }
        }
        
        if(i==s.length())
            return true;
        else
            return false;
        
        
    }
};
