// #define ppi pair<int,int>
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        //O(n) total time depends only on the element with maximum count
        vector<int> freq(26, 0);
        for(auto t:tasks) freq[t-'A']++;
        sort(freq.begin(), freq.end(), greater<int>()); // sort in descreasing order
        
        int maxLen = freq[0];
        int k=1;
        while(k<26 && freq[k]==maxLen) ++k;
        return max((maxLen-1)*(n+1)+k, (int)tasks.size());
        
        /*
        // printing of the task sequence TLE
        
        if(n==0)
            return tasks.size();
        int ts=tasks.size();
        
        //Logic: At any point choose that character/task whose count is the maximum
        
        vector<ppi>help;
        unordered_map<char,ppi>mp;
        
        for(int i=0;i<ts;++i){
            auto itr=mp.find(tasks[i]);
            if(itr==mp.end())
                mp[tasks[i]]=make_pair(1,0);
            else{
                ++itr->second.first;
            }
        }
        
        //sort the map in such a way that its in descending order of the count; better use ordered map
        
        for(auto x:mp){
            // cout<<x.first<<" ";
            // cout<<x.second.first<<","<<x.second.second;
            // cout<<endl;
            help.push_back(make_pair(x.second.first,x.first));
        }
        
        
        //sort descending wrt first
        sort(help.rbegin(),help.rend());
        
        int total=ts;
        int ans=0;
        
        
        vector<char>check;
        
        while(total>0){
            char find_ele='#';
            
//             for (auto itr = mp.begin(); itr != mp.end(); ++itr) 
//             { 
//                 if(itr->second.second==0 && itr->second.first>0){                
//                     --total;
//                     --itr->second.first;
//                     itr->second.second=n;
//                     find_ele=itr->first;
//                     break;
//                 }
//             }
            
            for (int ii = 0; ii < help.size(); ++ii) 
            {   
                auto itr=mp.find(help[ii].second);
                
                if(itr->second.second==0 && itr->second.first>0){                
                    --total;
                    --itr->second.first;
                    itr->second.second=n;
                    find_ele=itr->first;
                    break;
                }
            }
            
            ++ans;// every time time increases

            check.push_back(find_ele);

            // decrease one count for all the available chars except find_ele
            for (auto itr = mp.begin(); itr != mp.end(); ++itr) 
            { 
                if(itr->second.second>0){
                    if(find_ele=='#') // idle case
                        --itr->second.second;
                    else{
                        if(find_ele!=itr->first){ // not idle case
                            --itr->second.second;
                        }
                    }
                } 
            }
            
            help.clear();
            
            for(auto x:mp){
                // cout<<x.first<<" ";
                // cout<<x.second.first<<","<<x.second.second;
                // cout<<endl;
                help.push_back(make_pair(x.second.first,x.first));
            }
            
            //sort descending wrt first
            sort(help.rbegin(),help.rend());
            
            
            // for(auto x:mp){
            //     cout<<endl<<"................."<<x.first<<" ";
            //     cout<<x.second.first<<","<<x.second.second;
            //     cout<<"................."<<endl;
            // }
            // cout<<"End of iteration"<<total<<endl;
        }
            
        
        
        // cout<<endl;        
        // for(int i=0;i<check.size();++i){
        //     cout<<check[i]<<" ";
        // }
        // cout<<endl;
        // for(auto x:mp){
        //     cout<<x.first<<" ";
        //     cout<<x.second.first<<","<<x.second.second;
        //     cout<<endl;
        // }
        // cout<<ans;
        
        
        return ans;
        */
    }
};
