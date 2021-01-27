#define INF 1000000000
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // # define endl '\n'
    return 0;
}();

class NumArray {
public:
    vector<int>st; // segment tree
    vector<int>lazy; // lazy note tree
    int n;
    vector<int>num_copy;
    
    NumArray(vector<int>& nums) {


        n=nums.size();
        int tree_size=4*n+1;
        st.resize(tree_size); // size=4*maxN
        lazy.resize(tree_size); // by default 0
        // lazy.assign(120001,0);
        nums.insert(nums.begin(), 0); 
        num_copy=nums;
        build(1 , 1 , n, nums);
        
        // for(int i=0;i<=4*n;++i){
        //     cout<<st[i]<<" ";
        // }
        // cout<<endl;
    }
    
    void build(int si , int ss , int se, vector<int> &arr) // 1,1,n start, pass by reference should always be passed by reference for further function calls
    {
        if(ss == se) // base condition, for leaf nodes
        {
            st[si] = arr[ss]; // arr[ss]==arr[se], ss=se
            return;
        }

        int mid = (ss + se)/2;
        build(2*si , ss , mid, arr); // left child
        build(2*si+1 , mid+1 , se, arr); // right child

        st[si] = st[2*si] + st[2*si+1]; // first fill the leaf nodes then move up, sum -> sum query
        
    }

    
    void pointUpdate(int si, int ss, int se, int qs, int qe, int val){
        // portion of lazy tree
        if(lazy[si] != 0) // if there is pending update then pass it to further child node
        {
            int dx = lazy[si];
            lazy[si] = 0;
            st[si]+=dx*(se-ss+1); // apply the pending update
            
            if(ss != se) // pass on if children exist
            {
                lazy[2*si] += dx;
                lazy[2*si+1] += dx;
            }
        }

        if(ss > qe || se < qs) return;
	
        if(ss >= qs && se <= qe)
        { 
            int dx=(se-ss+1)*val; // as sum
            st[si]+=dx; // apply it to current node
            
            if(ss != se) // pass a pending update to children, if they exist
            {
                lazy[2*si]+=val;
                lazy[2*si+1]+=val;
            }
            return;
        }
        
        /*
        if(ss==se){
            st[si]=num_copy[ss];
            return;
        }
        */

        int mid=ss+(se-ss)/2;
        
        /*
        if(qi<=mid) pointUpdate(2*si,ss,mid,qs,qe,val); // go left
        else pointUpdate(2*si+1,mid+1,se,qs,qe,val); // go right
        */
        
        pointUpdate(2*si,ss,mid,qs,qe,val); // update left child
        pointUpdate(2*si+1,mid+1,se,qs,qe,val); // update right child
        
        st[si]=st[2*si]+st[2*si+1]; // sum-Query
    }
    
    void update(int index, int val) {
        
        // num_copy[index+1]=val; 
        
        // Naive Approach
        // build(1 , 1 , n, num_copy);
        
        // Better approach is to update the leaf node first then move up O(nlogn) for each query
        // pointUpdate(1,1,n,index+1);
        
        // More better approach is to use lazy propagation
        pointUpdate(1,1,n,index+1,index+1,val-num_copy[index+1]);// si,ss,se,qs,qe,val=(new_val-previous value)
        num_copy[index+1]=val; 
        
        // for(int i=0;i<=4*n;++i){
        //     cout<<st[i]<<" ";
        // }
        // cout<<endl;

    }
    
    int query(int si , int ss , int se , int qs , int qe)
    {
        // apply any pending update if present, during lookup also
        if(lazy[si] != 0) // if there is pending update then pass it to further child node
        {
            int dx = lazy[si];
            lazy[si] = 0;
            st[si]+=dx*(se-ss+1); // apply the pending update
            
            if(ss != se) // pass on if children exist
            {
                lazy[2*si] += dx;
                lazy[2*si+1] += dx;
            }
        }
        
        if(qe < ss || qs> se) // if query is out of bounds
            return 0;// contribute nothing to sum

        if(ss>=qs && se<=qe) // if query is inside bounds completely
            return st[si];

        int mid = ss + (se-ss)/2;
        int l = query(2*si , ss , mid , qs , qe); // go left
        int r = query(2*si+1 , mid+1 , se , qs , qe); // go right

        return l+r; // l+r, as sum -> sum query
    }
    
    int sumRange(int left, int right) {
        // cout<<left<<" "<<right<<" "<<n;
        return query(1,1,n,left+1,right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
