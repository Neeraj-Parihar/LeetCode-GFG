class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum;
        vector<int> rightSum;
        vector<int> ans;
        int sum = 0;

        for(auto num : nums){
            sum+=num;
        }

        for(auto num : nums){
            int temp = sum - num;
            sum = sum - num;
            rightSum.push_back(temp);
        }
        leftSum.push_back(0);
        int temp = 0;
        for(auto num : nums){
            temp+=num;
            leftSum.push_back(temp);
        }
        for(int i = 0 ; i < n ; i++){
            ans.push_back(abs(leftSum[i] - rightSum[i]));
        }
        return ans;
        
    }
};