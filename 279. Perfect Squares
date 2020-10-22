static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
bool is_ps(int n){
    int sq=sqrt(n);
    return (n==sq*sq);
}

class Solution {
public:
    int numSquares(int n) {

        // This is a mathematical solution
        // Based on Lagrange's Four Square theorem, there 
        // are only 4 possible results: 1, 2, 3, 4.
        
        
        // ans = 1
        if(is_ps(n))
            return 1;
        
        
        // else ans = 4
        
        // The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        
        while((n&3)==0)// eq to n%4==0
        {
            n>>=2;// eq to n=n>>2 //eq to n=n/2
        }
        
        if((n&7)==7)// eq to n%8==7
            return 4;
        
        
        // else ans = 2
        
        // we need to check only upto sqrt(n)
        

        for(int i=1;i<=sqrt(n);i++){
            if(is_ps(n-i*i))
                return 2;
        }        
            
        
        // else ans = 3
        return 3;
    }
};
