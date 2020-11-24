static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class NumArray {
public:
    vector<int> t;
    NumArray(vector<int>& nums) {
        
        if(nums.size()==0)
            t.push_back(0);
        else{
            t.push_back(nums[0]);
            for(int k=1;k<nums.size();k++){
                t.push_back(nums[k]+t[k-1]);
            }
        }
    
        
        
        
    }
    
    int sumRange(int i, int j) {
        
        // Brute-Force
        // int sum=0;
        // for(int k=i;k<=j;k++){
        //     sum+=num[k];
        // }
        // return sum;
        
        
        if (i==0)
            return t[j];
        else
            return t[j]-t[i-1];

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
