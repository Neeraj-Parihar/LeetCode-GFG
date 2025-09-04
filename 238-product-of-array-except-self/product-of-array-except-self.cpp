class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int > out(n,1);
        int prefix=1;
        for(int i = 0; i < n ;i++){
            out[i]=prefix;
            prefix*=nums[i];
        }
        int suffix=1;
        for(int i=n-1; i>=0 ;i--){
            out[i]*=suffix;
            suffix*=nums[i];
        }
        return out;
    }
};