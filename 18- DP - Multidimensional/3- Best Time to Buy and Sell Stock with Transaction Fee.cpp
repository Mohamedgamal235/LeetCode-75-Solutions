class Solution {
public:
    int dp[50005][2];
    // 0 -> buy , 1 -> sell
    int solve(int i , int status , vector<int>& prices, int& fee) {
        if (i == prices.size()) return 0;
        int& res = dp[i][status];
        if (~res)
            return res ;
        res = INT_MIN;
        int leave = solve(i + 1 , status , prices , fee);
        int pick ;

        if (status)
            pick = prices[i] - fee + solve(i + 1 , 0 , prices , fee);
        else
            pick = -prices[i] + solve(i + 1 , 1 , prices , fee);
        return res = max(pick , leave);
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , prices , fee);
    }
};