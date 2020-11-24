static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int countSubstrings(string s) {
        int counter = 0, n = s.size(),left=0,right=0;
        for (int i = 0; i < n; i++) {
            
            // For odd palindrome
            for (left = i, right = i; left >= 0 && right < n && s[left] == s[right]; left--, right++) {
                counter++;
            }
            
            // For even palindrome
            for (left = i, right = i + 1; left >= 0 && right < n && s[left] == s[right]; left--, right++) {
                counter++;
            }
        }
        return counter;
    }
};
