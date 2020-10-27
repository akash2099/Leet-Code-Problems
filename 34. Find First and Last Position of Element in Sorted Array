class Solution {
    int BST_first(vector<int> arr,int start, int end, int key){
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;// to avoid integer overflow            
            if(arr[mid]==key){
                res=mid;
                end=mid-1;
            }
            if(key>arr[mid])
                start=mid+1; //move right
            else if(key<arr[mid])
                end=mid-1; //move left
        }
        return res;
    }
    
    int BST_second(vector<int> arr,int start, int end, int key){
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;// to avoid integer overflow            
            if(arr[mid]==key){
                res=mid;
                start=mid+1;
            }
            if(key>arr[mid])
                start=mid+1; //move right
            else if(key<arr[mid])
                end=mid-1; //move left
        }
        return res;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        v.push_back(BST_first(nums,0,nums.size()-1,target));
        v.push_back(BST_second(nums,0,nums.size()-1,target));
        return v;
    }
};
