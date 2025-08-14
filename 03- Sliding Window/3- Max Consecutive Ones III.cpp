class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , r = 0 ;
        int zeros = 0 ;
        int ans = 0 ;
        while (r < nums.size()) {
            zeros += (nums[r] == 0) ;

            while (l <= r && zeros > k) {
                zeros -= (nums[l] == 0) ;
                l++ ;
            }

            ans = max(ans , r - l + 1) ;
            r++ ;
        }
        return ans ; 
    }
};