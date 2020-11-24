class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        if(nums.size()==1)
            return 0;
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            // cout<<mid;
            if(mid>0&&mid<nums.size()-1){
            // excluding outer indexes
                if((nums[mid]>nums[mid-1]) && (nums[mid]>nums[mid+1]))
                    return mid;
                
                if(nums[mid]<nums[mid+1])
                    start=mid+1;
                else if(nums[mid]<nums[mid-1])
                    end=end-1;
                
                // cout<<"mid"<<mid;
            }
            else if(mid==0){
                if(nums[0]>nums[1])
                    return 0;
                else
                    return 1;
            }
            else if(mid==nums.size()-1){
                if(nums[nums.size()-1]>nums[nums.size()-2])
                    return nums.size()-1;
                else
                    return nums.size()-2;
            }
        }
        
        return -1;
    }
};
