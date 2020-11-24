// #define ppi pair<int,int>
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        
        if(nums[0]==0)
            return false;
        
        int f=2;
        int i=nums.size()-1;
        int j=i;
        while(i>=0){
            
            if(f==2){ // non zero jump value accepted
                if(nums[i]==0){
                    --i;
                    f=1;
                }
                else{
                    --i;
                    --j;
                }
            }
            
            if(f==1){ // zero jump value
                if(j==(nums.size()-1)){
                    if(nums[i]>=(j-i)){
                        --i;
                        j=i;
                        f=2;
                    }
                    else{
                        --i;
                    }
                }
                else{
                    if(nums[i]>(j-i)){
                        --i;
                        j=i;
                        f=2;
                    }
                    else{
                        --i;
                    }
                }
            }
        }
        
        if(f==2)
            return true;
        
        return false;
    }
};
