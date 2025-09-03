class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int > ans;
        for(int i=0;i<nums.size();i++){
            int result = target - nums[i];
            if(ans.find(result)!=ans.end()){
                int j=ans[result];
                return {min(i,j),max(i,j)};
            }
            ans[nums[i]]=i; 
        }
        return {};
    }
};