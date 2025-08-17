class Solution {
public:
    bool possible(int k , long long h , vector<int>& piles) {
        long long hours = 0 ;
        for (auto x : piles)
            hours += (x + k - 1) / k;
        return hours <= h ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 , r = 1e9 , ans = -1 ;
        while (l <= r) {
            int mid = (l + r) / 2 ;
            if (possible(mid , h , piles))
                r = mid - 1 , ans = mid ;
            else
                l = mid + 1 ; 
        }
        return ans ; 
    }
};