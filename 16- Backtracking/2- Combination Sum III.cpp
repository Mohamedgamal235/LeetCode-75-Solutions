class Solution {
public:
    vector<vector<int>> ans ;
    void backtrack(int k , int n, int start , int sum , vector<int> &nums) {
        if (n == sum && nums.size() == k) {
            ans.push_back(nums);
            return;
        }
        if (sum > n || nums.size() > k) return;

        for (int i = start ; i <= 9 ; i++) {
            sum += i ;
            nums.push_back(i);
            backtrack(k , n , i + 1, sum , nums);
            sum -= i ;
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n == 1)
            return {};
        vector<int> nums;
        backtrack(k , n , 1, 0 , nums);
        return ans;
    }
};