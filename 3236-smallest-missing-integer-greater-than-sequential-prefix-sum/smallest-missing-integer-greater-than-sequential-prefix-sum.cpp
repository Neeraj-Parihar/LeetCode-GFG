class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        unordered_set<int> freq(nums.begin(),nums.end());

        for(int i = 1 ; i < n ; i++){
            if(nums[i] == nums[i - 1] + 1){
                x+= nums[i];
            }
            else break;
        }
        while(freq.count(x)){
            x++;
        }

        return x;
    }
};