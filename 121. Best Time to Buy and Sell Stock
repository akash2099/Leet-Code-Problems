static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>p1;
        int max=0;
        int size_price=prices.size();
        for (int i = size_price-1; i >=0; i--){
            if (i==size_price-1)
                max=prices[i];
            if(prices[i]>max)
                max=prices[i];
            p1.push_back(max);
        }
        reverse(p1.begin(), p1.end());
        max=-1;
        int dif=0;
        for(int i=0;i<size_price-1;i++){
            dif=p1[i+1]-prices[i];
            if(dif>max){
                max=dif;
            }
        }
        if(max<0)
            return 0;
        else
            return max;
    }
};
