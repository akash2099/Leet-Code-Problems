static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool divisorGame(int N) {
        if(N%2!=0){
            return false;
        }
        else{
           return true; 
        }
    }
};
