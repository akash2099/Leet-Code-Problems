static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {

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
    
    
public:
    int largestRectangleArea(vector<int>& heights) {
 
        int n=heights.size();

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
//             int temp;
//             int flag=0;
//             if(left[i]==0)
//                 ++flag;
//             if(right[i]==0)
//                 ++flag;
            
//             if(flag==2)
//                 temp=heights[i];
//             else if(flag==1)
//                 temp=abs(heights[i]*(right[i]+left[i]-i));
//             else
//                 temp=abs(heights[i]*(right[i]-left[i]-1));
            
            int temp=abs((right[i]-left[i]-1)*heights[i]);
            
            // cout<<i<<" "<<temp<<endl;
            
            if(max_area<temp)
                max_area=temp;
        }
        return max_area;
    }
};
