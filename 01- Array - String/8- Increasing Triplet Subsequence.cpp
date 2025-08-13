class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX, s = INT_MAX;
        for (int x : nums) {
            if (f >= x)
                f = x;
            else if (s >= x)
                s = x;
            else
                return true;
        }
        return false;
    }
};
