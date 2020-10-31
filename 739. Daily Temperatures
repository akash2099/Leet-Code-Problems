static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

// Simple NGR
// stack<int>s;
// for(int i=T.size()-1;i>=0;i--){
//     if(s.size()==0)
//         v.push_back(-1);
//     else if(s.size() && s.top()>T[i]){
//         v.push_back(s.top());
//     }
//     else if(s.size() && s.top()<=T[i]){
//         while(s.size() && s.top()<=T[i]){
//             s.pop();
//         }

//         if(!s.size())
//             v.push_back(-1);
//         else
//             v.push_back(s.top());
//     }


//     s.push(T[i]);
// }
// reverse(v.begin(),v.end());


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> v(T.size(),0);
        // NGR index;
        
        // stack<pair<int,int>>s;
        stack<int>s;

        for(int i=T.size()-1;i>=0;i--){
            while(!s.empty() && T[s.top()]<=T[i])
                s.pop();
            
            if(s.empty())
                v[i]=0;
            else
                v[i]=s.top()-i;
            
            s.push(i);
        }
    
        // reverse(v.begin(),v.end());
        
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i];
        // }
    
        return v;
    }
};
