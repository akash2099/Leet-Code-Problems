static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    int maxProfit(vector<int>& prices) {
    /*
    Suppose the first sequence is "a <= b <= c <= d", the profit is "d - a = (b - a) + (c - b) + (d - c)" without a doubt. And suppose another one is "a <= b >= b' <= c <= d", the profit is not difficult to be figured out as "(b - a) + (d - b')". So you just target at monotone sequences.
    */
        
    int sum = 0;
    for (size_t i = 1; i < prices.size(); ++i) 
        if(prices[i] - prices[i - 1]>0)
            sum+=prices[i] - prices[i - 1];
    return sum;
    // peak valley problem, consider only the monotonous sequence as we can buy and sell on the same day...... This is misleading.
    }
};
