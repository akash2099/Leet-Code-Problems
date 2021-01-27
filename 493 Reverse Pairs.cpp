/*
https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22
*/
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // # define endl '\n'
    return 0;
}();
class Solution {
public:

    int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1)
            return 0;
        auto mid = begin + (end - begin) / 2;
        int count = sort_and_count(begin, mid) + sort_and_count(mid, end);
        for (auto i = begin, j = mid; i != mid; ++i) {
            while (j != end and *i > 2L * *j)
                ++j;
            count += j - mid;
        }
        inplace_merge(begin, mid, end);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        return sort_and_count(nums.begin(), nums.end());
    }
    
    // int reversePairs(vector<int>& nums) {
    //     if(nums.size()==0)
    //         return 0;
    //     return mergeSort(nums, nums.size());
    // }
};
// better not to use inbuilt functions, added that soln in notes
