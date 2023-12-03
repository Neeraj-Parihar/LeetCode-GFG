class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,j=1;
        int profit=0;
        while(j<prices.size()){
            if(prices[i]<prices[j]){
                int diff=prices[j]-prices[i];
                profit=max(profit,diff);
                j++;
                
            }
            else{
                i=j;
                j++;
            }
        }
        return profit;
    }
};