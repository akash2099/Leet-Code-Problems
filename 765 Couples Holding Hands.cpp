static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // # define endl '\n'
    return 0;
}();
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        unordered_map<int,int>mp;// <element,index>    
        
        for(int i=0;i<row.size();++i)mp[row[i]]=i;
        
        int swaps=0;
        
        for(int i=0;i<row.size();i+=2){
            
            int first=row[i];
            int second=first^1; // (row[i] + row[i]%2?1:-1) = row[i]^1 
            int now=row[i+1];
            if(now!=second){
                
                ++swaps;
                
                // swap(row,i+1,mp[row[second]],mp);
                int swap_i=i+1;
                int swap_j=mp[second];
                
                // swap the numbers
                int temp=row[swap_i];
                row[swap_i]=row[swap_j];
                row[swap_j]=temp;

                
                // update the map
                mp[row[swap_i]]=swap_i;
                mp[row[swap_j]]=swap_j;
            }
        }
        return swaps;
    }
};
