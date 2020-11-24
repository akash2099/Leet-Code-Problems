// static int fastio=[](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return 0;
// }();
class Solution {
    int BST(vector<int> arr,int start, int end, int key){
        while(start<=end){
            int mid=start+(end-start)/2;// to avoid integer overflow            
            if(arr[mid]==key)
                return mid;
            if(key>arr[mid])
                start=mid+1; //move right
            else if(key<arr[mid])
                end=mid-1; //move left
        }
        return -1;
    }
    
    int get_pivot(vector<int> arr,int start, int end){
        while(start<=end){
            int mid=start+(end-start)/2;// to avoid integer overflow            
            int next=(mid+1)%arr.size();
            int prev=(mid-1+arr.size())%arr.size();
            // cout<<mid<<" "<<next<<" "<<prev<<" "<<start<<" "<<end<<endl;

            if(arr[mid]<=arr[next] && arr[mid]<=arr[prev])
                return mid;
            if(arr[end]>=arr[mid])
                end=mid-1; //first half unsorted
            else
                start=mid+1; //second half unsorted

            
            // cout<<mid<<" "<<next<<" "<<prev<<" "<<start<<" "<<end<<endl<<endl;
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int pivot=get_pivot(nums,0,nums.size()-1);
        if(nums[pivot]==target)
            return pivot;
        int left=BST(nums,0,pivot-1,target);
        int right=BST(nums,pivot,nums.size()-1,target);
        
        if (left!=-1)
            return left;
        else if(right!=-1)
            return right;
        else
            return -1;

    }
};
