class Solution {
public:

    //AS only 1 txn allowed K=1, we need to check K as well

    int helper(vector<int>& prices, int index, int K, vector<vector<int>> &v, int buy) {
        if (index >= prices.size() || (K <=0)) return 0;
        //else if (!buy && index == prices.size()-1) return prices[index];

        if (v[index][buy] != -1) return v[index][buy];
        
        if (buy) {
            int profitBuy = -prices[index] + helper(prices, index+1, K, v, !buy);
            int profitNotBuy = 0 + helper(prices, index+1, K, v, buy);
            return v[index][buy] = max(profitBuy, profitNotBuy);
        } else { //sell
            int profitSell = prices[index] + helper(prices, index+1, K-1, v, !buy);
            int profitNotSell = 0 + helper(prices, index+1, K, v, buy);
            return v[index][buy] = max(profitSell, profitNotSell);
        }
    }


/*
    int profit=0;
    int helper(vector<int>& prices, int index, int buy) {
        if (index == 0) return 0;
        //else if (!buy && index == 0) return prices[index];

        
        if (buy) {
            int profitBuy = -prices[index] + helper(prices, index-1, !buy);
            int profitNotBuy = 0 + helper(prices, index-1, buy);
            profit = max(profitBuy, profitNotBuy);
        } else { //sell
            int profitSell = prices[index] + helper(prices, index-1, buy);
            int profitNotSell = 0 + helper(prices, index-1, !buy);
            profit = max(profitSell, profitNotSell);
        }
        return profit;
    }
*/

    int maxProfit(vector<int>& prices) {
        // DP problem
        int n = prices.size();
        int K=1;

        //DP
        //K range from 0 to 1
        vector<vector<int>> v(n, vector<int>(2, -1));
        
        //buy =1
        return helper(prices, 0, K, v, 1);
    }
};
