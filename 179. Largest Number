// #define ppi pair<int,int>
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

/*
//My stupid sol
class Solution {
public:
    long long int convert_string_to_long_int(string s){
        long long int c=0;
        long long int multiplier=1;
        for(int i=s.length()-1;i>=0;--i){
            c+=s[i]*multiplier;
            multiplier*=10;
        }
        return c;
    }
    
    string largestNumber(vector<int>& nums) {
        
        int zero_count=0;
        
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0)
                ++zero_count;
        }
        
        if(zero_count==nums.size())
            return "0";
        
        for(int i=0;i<nums.size()-1;++i){
            for(int j=i+1;j<nums.size();++j){
                string x=to_string(nums[i])+to_string(nums[j]);//ij
                string y=to_string(nums[j])+to_string(nums[i]);//ji
                
                // convert string to int
                long long int x1=convert_string_to_long_int(x);
                long long int y1=convert_string_to_long_int(y);
                
                if(x1<y1)
                    swap(nums[i],nums[j]);
                
            }
        }
        
        string s;
        for(int i=0;i<nums.size();++i){
            s+=to_string(nums[i]); 
        }
        return s;
    }
};
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a); // while sorting ij>ji same logic as above
        });
        string ans;
        for(int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        return ans[0] == '0' ? "0" : ans;
    }
};


