static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        
        if(n<2)
            return true;
       
        bool s1_an=false,s2_an=false;

        int i=0,j=n-1;
        while(i<j){
            int x1=s[i]-'A';
            int y1=s[i]-'a';
            int z1=s[i]-'0';
            
            int x2=s[j]-'A';
            int y2=s[j]-'a';
            int z2=s[j]-'0';
            
            
            if((x1>=0 && x1<=25) || (y1>=0 && y1<=25) || (z1>=0 && z1<=9)){
                // alpha numeric s[i]
                s1_an=true;
            }
            else{
                s1_an=false;
                ++i;
            }
             
            
            if((x2>=0 && x2<=25) || (y2>=0 && y2<=25) || (z2>=0 && z2<=9)){
                // alpha numeric s[j]
                s2_an=true;
            }
            else{
                s2_an=false;
                --j;
            }
            
            if(s1_an && s2_an){
                if(tolower(s[i])==tolower(s[j])){
                    ++i;
                    --j;
                }
                else
                    return false;
            }
            
        }
        
        return true;
    }
};
