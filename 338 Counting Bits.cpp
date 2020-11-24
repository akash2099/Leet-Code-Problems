static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> countBits(int num) {
        
        // Using built in method
        // vector<int>t;
        // for(int i=0;i<=num;i++){
        //     t.push_back(__builtin_popcount(i));
        // }

        
        vector<int> t(num+1);// size and default value
        t[0]=0;
        for(int i=0;i<=num;i++)
        {
            t[i] = i%2 + t[i/2];
            // cout<<t[i]<<" ";           
        }
        return t;
    }
};
