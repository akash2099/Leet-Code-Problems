static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int countPrimes(int n) {
        // use sieve to find the prime numbers and their count
        if(n<2)
            return 0;
        n=n-1;
        int count=0;
        int isprime[n+1]; // false-> prime, true->not prime
        memset(isprime,0,sizeof(isprime));
        
        for(int i=2;i*i<=n;i++){
            if(isprime[i]==0){ // if prime
                for(int j=i*i;j<=n;j+=i)
                    isprime[j]=1;
            }
        }
        
        for(int i=2;i<=n;++i){
            if(isprime[i]==0) //prime
                ++count;
        }
        
        return count;
    }
};
