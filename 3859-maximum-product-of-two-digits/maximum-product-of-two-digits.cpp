class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;

        while(n > 0){
            int temp = n % 10;
            ans.push_back(temp);
            n/=10;
        }
        sort(ans.begin(),ans.end());
        int a = ans.size();
        return ans[a-2] * ans[a-1];
        
        
    }
};