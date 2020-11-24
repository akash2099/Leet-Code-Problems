static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        // if(n==2){
        //     if(s[0]==s[1])
        //         return s;
        //     else
        //         return s.substr(0,1);
        // }
              
        /*
        string rev_s=s;
        reverse(s.begin(), s.end());
        
    
        int t[n+1][n+1];
        
        // Initialization
        for(int i=0;i<n+1;i++){
            t[i][0]=0;
        }
        
        for(int j=1;j<n+1;j++){
            t[0][j]=0;
        }
        
        // Main code
        int max_index=-1;
        int max_index_value=-1;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if (s[i-1]==rev_s[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=0;
                
            }
        }
        
        // cout<<max_index<<" "<<max_index_value<<endl;
        // cout<<rev_s.substr(max_index-max_index_value-1+1, max_index-1)<<endl;
        
        // Checking
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                cout<<t[i][j]<<" ";
                if(max_index_value<t[i][j]){
                        max_index=j;
                        max_index_value=t[i][j];
                }
            }
            cout<<endl;
        }
        
        
        // cout<<max_index<<" "<<max_index_value<<endl;
        // cout<<rev_s.substr((max_index-1)-(max_index_value)+1, max_index-1)<<endl;
        // cout<<rev_s;
        // if((max_index-max_index_value)==max_index)
        //     return rev_s.substr(max_index-max_index_value, max_index_value);
        
        return rev_s.substr(max_index-max_index_value, max_index_value);
        // return "a";
        */
        
        if(n<=1)
            return s;
        
        int start=0;
     
        int i1,i2;
        int maxl=1; // the minimum LPS will be of length 1
        for(int i=1;i<n;i++){
            //considering even palindrome
            
            i1=i-1;
            i2=i+1;
            
            // Concept: 
            // s[i1]==s[i2] && i1>=0 && i2<n, this may create segmentation fault.
            // so better to use below, && left->right precedence
            
            while(i1>=0 && i2<n && s[i1]==s[i2]){
                if(i2-i1+1 > maxl){
                    maxl=i2-i1+1;
                    start=i1;
                
                }
                
                --i1;
                ++i2;
            }
            
            
            //considering odd palindrome
            
            i1=i-1;
            i2=i;
            
            while(i1>=0 && i2<n && s[i1]==s[i2]){
                if(i2-i1+1 > maxl){
                    maxl=i2-i1+1;
                    start=i1;
                   
                }
                
                --i1;
                ++i2;
            }
            
            
        }
        
        
        return s.substr(start,maxl);

        
        
        
    }
};
