static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    
    int stoi(char c){
        return c-'0';
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        int n=digits.length();
        // cout<<n;
        if(n==0)
            return ans;
        
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // for(int i=0;i<v.size();++i){
        //     cout<<v[i]<<endl;
        // }
        
        // cout<<v[2]<<endl;
        bool flag=true;
        queue<string>q1,q2;
        // i assume q1 already contains the digits[0] string characters, q2 is empty

        string pre=v[stoi(digits[0])];
        // cout<<endl<<pre<<endl<<digits[0];
        
        string new_st;
        // cout<<endl<<new_st;
        
        for(int j=0;j<pre.length();++j){
            new_st="";
            new_st.push_back(pre[j]);
            q1.push(new_st);
        }
        // cout<<endl;
        // while(!q1.empty()){
        //         cout<<q1.front()<<" ";
        //         q1.pop();
        // }
        
        int i=1;// i=1
        // initially q2 is empty
        while(i<n){
            string temp=v[stoi(digits[i])];            
            if(flag){
                while(!q1.empty()){
                    for(int j=0;j<temp.length();++j){
                        cout<<temp[j]<<" ";
                        new_st=q1.front();
                        new_st.push_back(temp[j]);
                        // string new_st=new_st+q1.front();
                        cout<<new_st<<" ";
                        q2.push(new_st);
                    }        
                    q1.pop();     
                }
                flag=false;
                // after this q1 is empty
            }
            else{
                while(!q2.empty()){
                    for(int j=0;j<temp.length();++j){
                        new_st=q2.front();
                        new_st.push_back(temp[j]);
                        // string new_st=new_st+q2.front();
                        q1.push(new_st);
                    }        
                    q2.pop();     
                }
                flag=true;
                // after this q2 is empty
            }    
            ++i;
        }
        
        if(flag){
            while(!q1.empty()){
                ans.push_back(q1.front());
                q1.pop();
            }
        }
        else{
            while(!q2.empty()){
                ans.push_back(q2.front());
                q2.pop();
            }
        }
        
      
        return ans;
        
        // O(4*4*4*4*4)=O(1024)
    }
};
