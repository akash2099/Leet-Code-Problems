static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(n<=1)
            return false;
        
        if(s[0]==')' || s[0]==']'|| s[0]=='}')
            return false;
        
        stack<char>st;
        st.push(s[0]);
        
        // cout<<"hi"<<s[1];
        
        for(int i=1;i<n;i++){
            if(s[i]=='(' || s[i]=='['|| s[i]=='{')
                st.push(s[i]);
            else if(st.size()>0){
                char a=st.top();
                if(a=='(')
                    a=')';
                else if(a=='[')
                    a=']';
                else
                    a='}';
                
                // cout<<a<<s[i]<<typeid(a).name()<<typeid(s[i]).name();
                
                if(a==s[i])
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
        // cout<<"hi";

        if(st.size()==0)
            return true;
        else
            return false;
    }
};
