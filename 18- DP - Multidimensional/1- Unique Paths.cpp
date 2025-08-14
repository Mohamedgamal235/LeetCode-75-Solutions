class Solution {
public:
    int dp[105][105];
    bool isValid(int i , int j , int n , int m) {
        return i >= 0 && j >= 0 && i < n && j < m ;
    }
    int solve(int i , int j , int n , int m ) {
        if (i == n - 1 && j == m - 1)
            return 1;

        int &res = dp[i][j] ;
        if(~res)
            return res ;

        int op1{} , op2{} ;
        if (isValid(i + 1 , j ,n , m))
            op1 += solve(i + 1 , j , n, m);
        if (isValid(i , j + 1 , n , m))
            op2 += solve(i , j + 1 , n, m);

        return res = op1 + op2 ;
    }

    int uniquePaths(int m, int n) {
        swap(n , m);
        memset(dp , -1 , sizeof(dp));
        return solve(0,0,n , m);
    }
};