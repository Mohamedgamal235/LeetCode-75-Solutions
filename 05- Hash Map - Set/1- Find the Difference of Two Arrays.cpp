class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        
        vector<int> lst1;
        for (int x : st1) {
            if (st2.find(x) == st2.end()) {
                lst1.push_back(x);
            }
        }
        
        vector<int> lst2;
        for (int x : st2) {
            if (st1.find(x) == st1.end()) {
                lst2.push_back(x);
            }
        }
        
        return {lst1, lst2};
    }
};