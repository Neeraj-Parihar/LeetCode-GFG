class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;

        for(int num : nums)
            totalSum += num;

        if(abs(target) > totalSum) return 0;
        if((target + totalSum) % 2 != 0) return 0;

        int subsetSum = (target + totalSum) / 2;
        int n = nums.size();

        vector<vector<int>> t(n+1, vector<int>(subsetSum+1, 0));

        // initialization
        for(int i = 0; i <= n; i++)
            t[i][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= subsetSum; j++) {
                if(nums[i-1] <= j) {
                    t[i][j] = t[i-1][j] + t[i-1][j - nums[i-1]];
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][subsetSum];
    }
};