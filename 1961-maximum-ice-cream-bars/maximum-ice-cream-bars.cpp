class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(),costs.end());

        if(costs.front() > coins)   return 0;
        int ans = 0;
        for(auto num : costs){
            if(num <= coins){
                ans++;
                coins-=num;
            }
        }
        return ans;
    }
};