class Solution {
public:
    int dp[505][505];
    string s , t ;
    int solve(int i , int j) {
        if (i == s.size() && j == t.size()) return 0;
        if (j == t.size()) return s.size() - i ;
        if (i == s.size()) return t.size() - j ;

        int &res = dp[i][j];
        if (~res)
            return res ;
        if (s[i] == t[j])
            return res = solve(i + 1 , j + 1);

        int op1 = 1 + solve(i + 1 , j); // delete from s
        int op2 = 1 + solve(i , j + 1); // delete from t
        int op3 = 1 + solve(i + 1 , j + 1); // replace

        return res = min({op1 , op2 , op3});
    }

    int minDistance(string word1, string word2) {
        s = word1 ;
        t = word2 ;
        memset(dp , -1 , sizeof(dp));
        return solve(0,0);
    }
};