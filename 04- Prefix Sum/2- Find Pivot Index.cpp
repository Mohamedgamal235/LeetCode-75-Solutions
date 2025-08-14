class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            long long left = prefix[i] - nums[i - 1];
            long long right = prefix[n] - prefix[i];
            if (left == right)
                return i - 1;
        }
        return -1;
    }
};
