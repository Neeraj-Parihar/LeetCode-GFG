class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        if (coins.empty()) return 0;

        sort(coins.begin(), coins.end());
        coins.erase(unique(coins.begin(), coins.end()), coins.end());

        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            if (coin <= 0 || coin > amount) continue;

            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];

                if (dp[j] > INT_MAX) {
                    dp[j] = INT_MAX;
                }
            }
        }

        return dp[amount];
    }
};