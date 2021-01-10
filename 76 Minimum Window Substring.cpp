static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    string minWindow(string s, string t) {
        //My Solution , O(N)
        int n=s.length(),m=t.length();
        if(n<m)
            return "";
        
        // Step1: preprocess to create the ps vector and actual_freq hash map
        vector<pair<char,int>>ps;//{ (A,0), (B,3), (C,5), (B,9), (A,10), (C,12) }
        unordered_map<char,int>actual_freq;
        for(int x=0;x<m;++x){
            ++actual_freq[t[x]];
        }
        
        for(int x=0;x<n;++x){
            if(actual_freq[s[x]]!=0){
                ps.push_back(make_pair(s[x],x));
            }
        }

        int ps_size=ps.size();
        
        cout<<"Verifying Step 1"<<endl;
        for (auto x : actual_freq) 
            cout << x.first << " " << x.second << endl;
        
        for(int l=0;l<ps_size;++l){
            cout<<l<<" ( "<<ps[l].first<<" , "<<ps[l].second<<" )"<<endl;
        }
        
        
        // Step 2: First find the i an j for which the range contains all the entries of t and also hash map
        unordered_map<char,int>freq;// current range freq
        int flag=m;// if flag becomes 0 then we got our i and j
        int i=0,j=0;
        while(j<ps_size){
            cout<<"debug : "<<ps[j].first<<" "<<ps[j].second<<endl;
            char cs=ps[j].first;
            ++freq[cs];
            
            if(freq[cs]<=actual_freq[cs]){
                --flag;
                cout<<"decrement-flag"<<endl;
            }
            
            ++j;
            
            if(flag==0){
                break;
            }
        }
        
        // if t is not fully present in s
        if(flag!=0)
            return "";
        
        --j; // decrementing the j to reach its correct position
        
        cout<<"Verifying Step 2"<<endl;
        cout<<i<<" - "<<j<<endl;
        for (auto x : freq) 
            cout << x.first << " " << x.second << endl; 
        
        
        // Step 3: Then run the actual algorithm
        int min_i=ps[i].second,min_j=ps[j].second;
        int min_length=min_j-min_i+1;
        while(true){

            while(freq[ps[i].first]>actual_freq[ps[i].first]){
                --freq[ps[i].first];
                ++i;
            }
            
            int k=j+1;
            while(k<ps_size && ps[k].first!=ps[i].first){
                ++freq[ps[k].first];// as we are including new element in the range we must increase the freq of that element
                ++k;
            }
            
            cout<<"debug 2 : "<<ps[i].first<<" i= "<<i<<" j= "<<j<<" k= "<<k<<endl;
            
            int curr_length=ps[j].second-ps[i].second+1;
            if(min_length>=curr_length){
                min_length=curr_length;
                min_i=ps[i].second;
                min_j=ps[j].second;
            }

            if(k<ps_size){ // remove the first element without changing the freq hash map
                j=k;
                ++i;
            }
            else{ // no valid range found end of loop
                break;
            }
            
        }
        
        cout<<"Verifying Step 3"<<endl;
        cout<<min_i<<" - "<<min_j<<" : "<<min_length<<endl;

        // start_index=min_i, end_index=min_j, min_length=end_index-start_index+1
        return s.substr(min_i,min_length);

        // Optimization Left using Hash array instaed of Maps, working with integers instead of chars, bla bla...
    }
};
