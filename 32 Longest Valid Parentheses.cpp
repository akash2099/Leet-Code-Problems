static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        if(n<=1){
            return 0;
        }
        
        int t[n];
        memset(t,0,sizeof(t));
        stack<pair <int, char>>st;
        
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(!st.empty()){
                    pair<int,char>temp;
                    temp=st.top();
                    t[temp.first]=1;
                    t[i]=1;
                    st.pop();
                }
                
            }
            else{
                pair<int,char>temp;
                temp.first=i;
                temp.second=s[i];
                st.push(temp); //push '('   
            }
            // cout<<i<<" ";
            // if(!st.empty())
            //     cout<<st.top()<<endl;
        }
        
        int ans=0;
        int temp_ans=0;
        for(int i=0;i<n;i++){
            if(t[i]==1){
                ++temp_ans;
                if(ans<temp_ans)
                    ans=temp_ans;
            }
            else
                temp_ans=0;
        }
        
        return ans;
        
        
//         cout<<s;
//         stack<pair <int, char> PAIR1>st1;
//         maxl=0;
//         int ans1=0;
//         for(int i=n-1;i>=0;i--){
//             if(s[i]=='('){
//                 if(!st1.empty()){
//                     maxl+=2;
                    
//                     if(ans1<maxl)
//                         ans1=maxl;
                    
//                     st1.pop();
//                 }
//                 else
//                     maxl=0;
//             }
//             else{
//                 st1.push(s[i]);// push '('   
//             }
//             // cout<<i<<" ";
//             // if(!st1.empty())
//             //     cout<<st.top()<<endl;
//         }

//         return min(ans,ans1);
        
    }
};
