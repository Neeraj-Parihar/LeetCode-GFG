class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int Min=nums[l];
        while(l<=r){
            if(nums[l]<nums[r]){
                Min=min(nums[l],Min);
                break;
            }
            int mid=l+(r-l)/2;
            if(nums[mid]>=nums[l]){
                Min=min(Min,nums[l]);
                l=mid+1;
            }
            else{
                r=mid-1;
                Min=min(nums[mid],Min);
            }
        }
        return Min;
        
        
        
        
    }
};