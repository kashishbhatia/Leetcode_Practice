class Solution {
public:

    int minCostClimbingStairsHelper(vector<int>& cost, int n, int dp[]) {
        if (n == 0) return cost[0];
        if (n == 1) return cost[1];

        
        if (dp[n] != -1) return dp[n];

        int oneStep = cost[n] + minCostClimbingStairsHelper(cost, n-1, dp);
        int twoSteps = cost[n] + minCostClimbingStairsHelper(cost, n-2, dp);

        dp[n] = min(oneStep, twoSteps);

        return dp[n];

    }

    int minCostClimbingStairs(vector<int>& cost) {
       // extension of count ways to climb stairs

        int n = cost.size();
       int dp[cost.size()+1];

       for (int i = 0; i<=cost.size(); i++)
            dp[i] = -1;

        //return (minCostClimbingStairsHelper(cost, n-1, dp)); // Why this isnt work
        int ans = min(minCostClimbingStairsHelper(cost, n-2, dp), minCostClimbingStairsHelper(cost, n-1, dp));
        return ans;
    }
};
