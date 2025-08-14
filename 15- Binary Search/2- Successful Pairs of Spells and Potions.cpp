class Solution {
public:
#define ll long long
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin() , potions.end());
        vector<int> ans(n) ;
        for (int i = 0 ; i < n ; i++) {
            ll l = 0 , r = m - 1 ;
            while (l <= r) {
                ll mid = l + (r - l) / 2 ;
                ll mul = (ll)spells[i] * (ll)potions[mid];
                if (mul >= success)
                    r = mid - 1 ;
                else
                    l = mid + 1 ;
            }
            ans[i] = m - l ;
        }
        return ans ;
    }
};