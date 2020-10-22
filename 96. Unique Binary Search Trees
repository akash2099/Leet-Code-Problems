static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int numTrees(int n) {
        
//     set t[0]=1; just for easy calculation.

//     t[1]=1, means when there is one node, return 1.

//     When n=2, {1,2}:

//     If '1' is root, there is 0 node left to build up left branch, and 1 node left to build up right branch. Thus when n=2, '1' is root, there are t[0] * t[1] trees.

//     If '2' is root, there is 1 node to build left branch, and 0 node to build right branch. Thus n=2, '2' is root, there are t[1] * t[0] trees.

//     So when n=2, there are t[0]*t[1] + t[1]*t[0]; trees.

//     Use the 'root' to divide 1...n into two parts, then there are t[remaining number of left] * t[remaining number of right] trees for each 'root'.
    
    
        vector<int> t(n + 1);
        t[0] = t[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
                t[i] += t[j - 1] * t[i - j];
            // cout<<t[i];
            t[i]=t[i]<<1;
            // cout<<t[i];

            if (i & 1)// eq to i%2==0
                t[i] += t[i / 2] * t[i / 2];//Plus the middle 'root' trees. if odd
        }

	    return t[n];
    }
};
