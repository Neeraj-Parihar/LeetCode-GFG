class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int count=0;
        while(count<2){
            for(auto it: nums){
                ans.push_back(it);
            }
            count++;
        }
        return ans;
    }
};