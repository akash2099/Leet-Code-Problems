static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find get xor of all elements of vector
        long long int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff; // ~(diff - 1) = - (diff - 1) - 1 = -diff

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            //Since, only one pair has this particular bit set or not set others willcancel out
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;// other will cancel out
            }
            else // the bit is set
            {
                rets[1] ^= num;// other will cancel out
            }
        }
        return rets;
    }
};
