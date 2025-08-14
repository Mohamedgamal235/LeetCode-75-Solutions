class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int ,int>> arr ;
        int cnt = 0 ;
        for (int i = nums.size() - 1 ; i >= 0 ; i--) {
            if (nums[i])
                cnt++ ;
            else {
                if (arr.empty())
                    arr.push_back({-1 , cnt});
                else {
                    pair<int , int>& last = arr.back();
                    last.first = cnt ;
                    arr.push_back({-1 , cnt});
                }
                cnt = 0 ;
            }
        }

        if (arr.empty())
            return nums.size() - 1 ;
        
        pair<int, int>& last = arr.back();
        last.first = cnt ;

        int ans = 0 ;
        for (auto [f , s] : arr)
            ans = max(ans , f + s);

        return ans ;
    }
};