class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, average = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];
        average = round((sum / k) * 1e5) / 1e5;
        for (int i = k; i < nums.size(); i++) {
            sum -= nums[i - k];
            sum += nums[i];
            average = max(average, round((sum / k) * 1e5) / 1e5);
        }
        return average;
    }
};
