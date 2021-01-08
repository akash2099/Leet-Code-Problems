static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        
        // cout<<n<<" ";
        
        for(int i=0;i<32;++i){
            
            if(i>0){
                ans<<=1; // shift one bit
            }
            
            if(n & (1<<i)){ // i th bit in n
                // cout<<1; 
                ans=ans|1; // making the current LSB to 1
            }
            // else{
                // cout<<0;
            // }
           
            // cout<<ans<<" ";
        }
        // cout<<endl;
               
        return ans;
    }
};
