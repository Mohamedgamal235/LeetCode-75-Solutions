class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1) ;
        ans[0] = 0 ;
        for (int i = 1 ; i <= n ; i++) {
            for (int bit = 0 ; bit <= 31 ; bit++) {
                if ((i >> bit) & 1LL)
                    ans[i]++;
            }
        }
        return ans ; 
    }
};