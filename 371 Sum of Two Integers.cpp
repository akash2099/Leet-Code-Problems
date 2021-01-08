static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
/*
Set nth bit of a number
number |=  (1 << n);
*/
class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int carry=0;
        int curr;
        int x,y;
        for(int i=0;i<32;++i){
            int f=(1<<i);
            if(a&f) // i th bit of a
                x=1;
            else
                x=0;
            
            if(b&f) // i th bit of b
                y=1;
            else
                y=0;
            
            curr=x^y^carry; // current bit value            
            carry=x&y || ((x|y)&carry); // carry for next
            
            // cout<<curr<<" "<<carry;
            
            if(curr)
                ans|=f; // set ith bit of a number
            
            // cout<<endl;
        }
        return ans;
    }
};
