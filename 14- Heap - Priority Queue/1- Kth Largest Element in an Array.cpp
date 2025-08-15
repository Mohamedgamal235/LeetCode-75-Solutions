class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        reverse(nums.begin() , nums.end());
        return nums[k-1];
    }
};


// another way using priority_queue

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (auto x : nums)
            pq.push(x);

        k-- ;
        while (!pq.empty() && k--)
            pq.pop();
        return pq.top();
    }
};