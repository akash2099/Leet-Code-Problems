static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
bool check_pair(string a){
    if(a[0]=='0') 
        return false;
    else{
        if(stoi(a)<=26)
            return true;
    }
    return false;
}

class Solution {
public:
    int numDecodings(string s) {

        int n=s.length();
 
        if(n==0||s[0]=='0')
            return 0;
        
        if(n==1 && s[0]!='0'){
            return 1;
        }
        
        //preprocessing removing pairs with '0'
        //"201205581560415"(Output:0)
        
        //creating a tag vector for keeping the tag of 0 pair ending index's
        vector<int>tag;
        
        string a="";
        a.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                if(check_pair(s.substr(i-1,2))){
                    a=a.substr(0,a.length()-1);//remove last element of a
                    if(i!=(n-1)){
                        tag.push_back(a.length());
                    }   
                }
                else{
                    return 0;
                    break;
                }  
            }
            else{
                a.push_back(s[i]);
            }
            // cout<<a<<" ";
        }
        cout<<endl<<a<<endl;
        
        for(int i=0;i<tag.size();i++){
            cout<<tag[i]<<" ";
        }
        
        int tn=tag.size();
        int k=0;
        if(tn>=1 && tag[k]==0){
            ++k;
        }
        
        // cout<<" HI "<<k<<endl;
        

        
        
        int m=a.length();
        if(m<=1)
            return 1;
                              
        // considering m>=2
        int first=1;
        int second=1;
        
        if(k<tn && tag[k]==1){
            second=1;
            ++k;
        }
        else{
            if(check_pair(a.substr(0,2)))
                second=2;
            else
            second=1;
        }
        
        cout<<endl<<k<<endl;

           
        int curr=second;
        
        cout<<"First_print: "<<first<<" "<<second<<" "<<curr<<endl;
        
        for(int i=2;i<m;i++){
            cout<<endl<<" "<<i<<endl;
            if(k<tn && tag[k]==i){
                // Current index contains tag
                curr=second;
                ++k;
                cout<<" Found a tag ";
            }
            else{
                if(check_pair(a.substr(i-1,2))){
               
                    if(check_pair(a.substr(i-2,2))){
                        //overlap detected sum of last two
                        curr=first+second;
                        cout<<" overlap "<<first<<" + "<<second<<" ";
                    }
                    else{
                        curr=first<<1;
                        // since it is a pair only no overlap hence dobling the possibility
                        cout<<" no ovelap "<<first<<" *2 ";
                    }
                }
                else{
                    // if not pair then same count continues
                    curr=second;
                    cout<<" not pair same continues ";
                }
                //continue steps
                // first=second;
                // second=curr;

            }
            //continue steps
            first=second;
            second=curr;
           
            
            cout<<first<<"-"<<second<<"-"<<curr;
        }
           
        return curr;
        // "12318162021561214326102136987456123110" idkmf...ignore
        
    }
};
