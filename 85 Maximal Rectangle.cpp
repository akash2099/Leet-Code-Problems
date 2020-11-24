static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {
    
    // Maximum Rectangle Area Histogram Code
     void nsr(vector<int>& v, vector<int>T){
        
        stack<int>s;

        for(int i=T.size()-1;i>=0;i--){
            while(!s.empty() && T[s.top()]>=T[i])
                s.pop();
            
            if(!s.empty())
                v[i]=s.top();
            // else
            //     v[i]=-1;// this will never come
            
            s.push(i);
        }
    }
    
    void nsl(vector<int>& v, vector<int>T){
        
        stack<int>s;

        for(int i=0;i<T.size();i++){
            while(!s.empty() && T[s.top()]>=T[i])
                s.pop();
            
            if(!s.empty())
                v[i]=s.top();
            // else
            //     v[i]=-1;// this will never come
            
            s.push(i);
        }
    }
    
    int MAH(vector<int>heights,int n){
        
        vector<int>left(n+2);
        vector<int>right(n+2);
  
        // adding pseduo indexed at the end
        heights.insert(heights.begin()+0,-1);
        heights.push_back(-1);

        nsr(right,heights);
        nsl(left,heights);

        int max_area=0;
        
//         for(int i=1;i<=n;i++)
//             cout<<left[i]<<" ";
        
//         cout<<endl;
        
//         for(int i=1;i<=n;i++)
//             cout<<right[i]<<" ";
        
//         cout<<endl;
        
        for(int i=1;i<=n;i++){
            
            int temp=abs((right[i]-left[i]-1)*heights[i]);
            
            // cout<<i<<" "<<temp<<endl;
            
            if(max_area<temp)
                max_area=temp;
        }
        return max_area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size();
        if (n==0)
            return 0;
    
        /*
        before
        //Stack implementnation + DP will check later
        int t[m][n];
        memset(t,0,sizeof(t));
        
        int ans=0;// initializing to 0 minimum

        for(int i=0;i<m;i++){
            t[i][0]=matrix[i][0]-'0';
            ans=max(ans,t[i][0]);
        }
        
        for(int j=0;j<n;j++){
            t[0][j]=matrix[0][j]-'0';
            ans=max(ans,t[0][j]);
        }
          
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<t[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                // considering t[i][j] is the bottom right corner for a square box
                if(matrix[i][j]=='1')
                    t[i][j]=1+min(t[i-1][j-1],min(t[i-1][j],t[i][j-1]));

                
                ans=max(ans,t[i][j]);
            }
        }
        
        int h,w;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(t[i][j])
                    h=t[i][j];
                
                int width=t[i-1][j];
                t[i][j]
            }
            cout<<endl;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<t[i][j]<<" ";
            }
            cout<<endl;
        }
        
        // cout<<ans;
        
        return ans*ans;
        */
        
        // After
        int ans=0;
        vector<int> v(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    v[j]+=1;
                else
                    v[j]=0;
            }
            int temp=MAH(v,n); // n is no. of columns
            if(ans<temp)
                ans=temp;    
        }
        return ans;

    }
};
