static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 1st approach, Time: O(2N), Space: O(N)
        /*
        if(s.length()==0)
            return 0;
        
        int i=0,j=0,max_length=0;
        set<char>temp;// current set of distinct characters
        
        while(i<s.length()){
            
            char c=s[i];

            while(temp.find(c)!=temp.end()){
                temp.erase(temp.find(s[j])); // erase the s[j] from the set
                ++j;// remove elements from temp set and increment j
            }
            
            temp.insert(c);// if c is no longer present in temp so insert c to temp
            
            max_length=max(max_length,i-j+1);
            
            // int new_length=i-j+1;
            // if(max_length < new_length){ // max_length needs to be updated
            //     max_length = new_length;
            // }
            
            ++i;// proceed further
        }

        return max_length;
        */
        
        // Time: O(N), Space: O(1), for strings
        // Explanation YOuTube Video
        // Hash Array is faster than Hash Map
        int res = 0;
        int mp[128]={0};
        // unordered_map<char,int>mp; // by default 0
        for (int right = 0, left = 0; right < s.length(); right++) { // right is the current position
            
            // if the element is not present in the map then the left may get modified
            left = max(mp[s[right]], left); // Using last seen appraoch
            
            // modify the right, store the current last position in the map
            mp[s[right]] = right+1;
            
            // update the length
            res = max(res, right - left + 1);
        }
        return res;
    }
};
