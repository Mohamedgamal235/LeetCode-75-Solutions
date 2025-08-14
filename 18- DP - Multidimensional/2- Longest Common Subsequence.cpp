class Solution {
public:
    int dp[1005][1005];
    int solve(int i , int j , string&s1 , string&s2) {
        if (i == s1.size())
            return 0;
        if (j == s2.size())
            return 0;

        int &res = dp[i][j];
        if (~res)
            return res ;

        if (s1[i] == s2[j])
            return res = 1 + solve(i + 1 , j + 1 , s1 , s2);

        return res = max(solve(i + 1 , j , s1 , s2 ) , solve(i , j + 1 , s1 , s2 ));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 ,0, text1 , text2);
    }
};