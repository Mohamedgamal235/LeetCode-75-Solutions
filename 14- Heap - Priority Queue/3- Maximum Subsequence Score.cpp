class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int , int>> arr ;
        int n = nums1.size();
        for (int i = 0 ; i < n ; i++)
            arr.emplace_back(nums2[i] , nums1[i]);
        sort(arr.rbegin() , arr.rend()); 
        // larg to small to get min element on nums2 when iterative

        priority_queue<int , vector<int> , greater<int>> pq ;
        long long sum = 0 , ans = -1 ; 
        for (auto [num2 , num1] : arr) {
            pq.push(num1);
            sum += num1 ;
            if (pq.size() > k) {
                int x = pq.top();
                sum -= x ;
                pq.pop();
            }
            if (pq.size() == k)
                ans = max(ans , sum * (long long)num2);
        }
        return ans ; 
    }
};