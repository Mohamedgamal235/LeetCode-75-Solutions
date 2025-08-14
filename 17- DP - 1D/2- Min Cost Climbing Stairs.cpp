class Solution {
public:
#define ll long long
    ll mem[1005] ;
    ll dp(int i, vector<int>& cost) {
        if (i >= cost.size())
            return 0;

        if (mem[i] != -1)
            return mem[i] ; 
        
        int op1 = dp(i + 1 , cost) + cost[i];
        int op2 = dp(i + 2 , cost) + cost[i];

        return mem[i] = min(op1 , op2) ; 
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(mem , -1 , sizeof mem);
        int op1 = dp(0 , cost) ;
        memset(mem , -1 , sizeof mem);
        int op2 = dp(1 , cost) ;

        return min(op1 , op2) ;
    }
};