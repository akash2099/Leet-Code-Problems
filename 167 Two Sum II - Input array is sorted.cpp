static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=n-1;
        
        while(i<j){
            
            int value=numbers[i]+numbers[j]; // current pair sum
            
            if(value==target){
                return {i+1,j+1}; // since there is exactly one output
                // ++i;
                // --j;
            }
            else if(value>target){
                --j;
            }
            else{
                ++i;
            }
        }
        return {};
    }
};
