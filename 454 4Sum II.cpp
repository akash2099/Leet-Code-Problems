// static const auto speedup = []() {
// std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr); return 0;
// }();



static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        /*
        
        // TLE Naive Approach
        int I=A.size();
        int J=B.size();
        int K=C.size();
        int L=D.size();
        // cout<<I<<J<<K<<L;
        if(!(I&&J&&K&&L))
            return 0;
        

        int sum=0;
        for(int i=0;i<I;i++){
            for(int j=0;j<J;j++){
                for(int k=0;k<K;k++){
                    for(int l=0;l<L;l++){
                        if(!(A[i]+B[j]+C[k]+D[l]))
                           ++sum;
                    }
                }
            }
        }
        return sum;
        
        */
        
        /*
        // O(n^2) approach A+B=-(C+D)
        
        //since all are of same length
        int n = A.size();
        if(n==0)
            return 0;
        
        int sum=0;
        unordered_map<int,int> sumMap1;
        unordered_map<int,int> sumMap2;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int sum1 = A[i] + B[j];
                int sum2 = C[i] + D[j];
                sumMap1[sum1]++;
                sumMap2[sum2]++;
            }
        }
        for(auto num1 : sumMap1) {
            int number = num1.first;
            if(sumMap2.find(-1 * number) != sumMap2.end()) {
                sum += num1.second * sumMap2[-1 * number];
            }
        }

        return sum;
        */
        
        
        // faster more optimized
        int count = 0;
        unordered_map<int,int> umap;
        umap.reserve(C.size()*D.size());// reserve limited space
        
        for(int c : C)
            for(int d : D)
                ++umap[c+d];
        
        
        for(int a : A)
                for(int b : B){
                            const auto itr = umap.find(-a-b);
                            if(itr != umap.end())
                                count += itr->second;
                        }
                                
        return count;

    }
};
