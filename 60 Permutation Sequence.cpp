static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    /*
    int count;
    string ans;
    void backtrack(string curr, vector<int>& mp,int n,int k){
            cout<<"Hi"<<curr<<endl;
            if(curr.length()==n){
                ++count;
                if(count==k)
                    ans=curr;
            }
            else{
                for(int i=1;i<=n;++i){ // choose a valid i
                    
                    if(mp[i-1]==0){
                        ++mp[i-1]; // take decision
                        backtrack(curr+to_string(i),mp,n,k); // continue with the taken decision

                        --mp[i-1]; // undo decision
                    }
                    
                    if(count==k) // ans found
                        break;
                }
            }
    }
    
    string getPermutation(int n, int k) {
        // unordered_map<int,int>mp;
        vector<int>mp(n,0);
        count=0;
        ans="";
        backtrack("",mp,n,k);
        return ans;
    }
    */
    
    // better approach O(n^2)
    
    string getPermutation(int n, int k) {
        string ans="";
        vector<int> num;
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
            num.push_back(i);
        }
        --k;
        for (int i = 0; i < n; i++) {
            fact /= (n - i);
            int index = (k / fact);
            ans+=to_string(num[index]);
            num.erase(num.begin() + index);
            k -= index * fact;
        }
        return ans;
    }
    
};
