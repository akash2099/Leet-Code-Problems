static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    double myPow(double x, int n) {
        //using binary exponentiation
        
        if(x==1)
            return x;
        
        if(n == 0)
            return 1;
        if(n<0){
            // n = -n;
            x = 1/x;
        }
        n=abs(n);
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
        
        
//         if(n==0)
//             return 1;
        
//         double res=1;
//         if(n<0){
//             x=1/x;
//             n=-n;
//         }
        
//         while(n){
//             if(n%2) // power is not divisible by 2
//                 res*=x; // n--, res=result=result*base
//             else
//                 x*=x;
            
//             n=n>>1; // n/=2, x=base=base*base
//         }
        
//         return res;
    }
};
