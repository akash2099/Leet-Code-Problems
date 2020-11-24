static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
/*
int solve(vector<int> c,int n,int index,int *t){
    //Base condition
    if (t[index]!=-1)
        return t[index];
    
    
    if (index==n-1)
        return c[index];
    if (index==n-2)
        return c[index];
    

    
    //Hypothesis
    int first,second;
    if (t[index+1]!=-1)
        first=t[index+1];
    else
        first=solve(c,n,index+1,t);
        
    if (t[index+2]!=-1)
        second=t[index+2];
     else
        second=solve(c,n,index+2,t);
         
    int ans=c[index]+min(first,second);
    return t[index]=ans;
}
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      //example: [0,101,100,5,10,500] 
        int size_cost=cost.size();
        if (size_cost==1|| size_cost==0)
            return 0;
        else if(size_cost==2)
            return min(cost[0],cost[1]);
        else
            {
                // Recursion
                // return min(solve(cost,size_cost,0),solve(cost,size_cost,1));

                //Memorization
                // int t[size_cost];
                // memset(t,-1,sizeof(t));
                // t[size_cost-1]=cost[size_cost-1];
                // t[size_cost-2]=cost[size_cost-2];
                // return min(solve(cost,size_cost,0,t),solve(cost,size_cost,1,t));
            
                //Bottom Up- Top Down
                int t1[size_cost];
                t1[size_cost-1]=cost[size_cost-1];
                t1[size_cost-2]=cost[size_cost-2];
                for(int i=size_cost-3;i>=0;i--){
                    t1[i]=cost[i]+min(t1[i+1],t1[i+2]);
                }
                return min(t1[0],t1[1]);
            }

    }
};
