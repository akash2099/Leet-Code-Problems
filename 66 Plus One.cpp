static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        
        int carry=0;
        for(int i=n-1;i>=0;--i){
            
            int curr=digits[i]+carry;
            
            if(i==n-1){
                ++curr;
            }
            
            carry=curr/10;
            
            digits[i]=curr%10;
            
        }
        
        if(carry>0)
            digits.insert(digits.begin(), carry);
        
        return digits;
        
    }
};
