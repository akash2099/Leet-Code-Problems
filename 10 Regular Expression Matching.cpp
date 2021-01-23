static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    // unordered<,bool>mp;
    bool isMatch(string s, string p) {
        // cout<<endl<<endl<<s<<" "<<p<<endl;
        int sn=s.length();
        int pn=p.length();
        
        if(sn==0){
            if(pn==0)
                return true;
            
            if(pn==1)
                return false;

            if(pn>=2){
                if(p[pn-1]!='*')
                    return false;
            }
        }
       
        if(pn==0 && sn>0)
            return false;
        
        --sn;
        --pn;
        
        char c=p[pn];        
        bool ans=false;
        if(c=='*'){
            char pre=p[pn-1];
            ans = ans || isMatch(s.substr(0,sn+1),p.substr(0,pn-1));
            if(!ans){    
                for(int i=0;i<=sn;++i){
                    // cout<<pre<<"-"<<sn-i<<" ----------- "<<i<<endl;
                    if(pre=='.'){
                        ans=ans || isMatch(s.substr(0,sn-i),p.substr(0,pn-1));
                    }
                    else if(pre == s[sn-i]){
                        ans = ans || isMatch(s.substr(0,sn-i),p.substr(0,pn-1));
                    }
                    else{
                        return false;
                        break;
                    }
                    
                    if(ans)
                        break;
                }
            }
        }
        else if(c == '.'){ 
            ans = isMatch(s.substr(0,sn),p.substr(0,pn));             
        }
        else{
            if(c == s[sn])
                ans = isMatch(s.substr(0,sn),p.substr(0,pn));
        }
        // cout<<endl;
        return ans;
        
    }
};
