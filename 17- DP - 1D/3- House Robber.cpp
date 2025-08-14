class Solution {
public:
    int dp[101];
    int solve(int i  , vector<int>& nums) {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        dp[i] = solve(i + 2 , nums) + nums[i] ;
        dp[i] = max(dp[i] , solve(i + 1 , nums));

        return dp[i] ;
    }

    int rob(vector<int>& nums) {
        memset(dp , -1 , sizeof dp );
        return solve(0, nums);
    }
};