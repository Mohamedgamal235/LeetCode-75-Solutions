class Solution {
public:
#define ll long long
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size() ;
        priority_queue<int , vector<int> , greater<int>> pq1 , pq2;
        deque<int> remain ;
        int lstIndex = n - candidates;
        for (int i = 0 ; i < n ; i++) {
            if (i < candidates)
                pq1.push(costs[i]);
            else if (i >= lstIndex)
                pq2.push(costs[i]);
            else
                remain.push_back(costs[i]);
        }

        ll cost = 0 ;
        while (k--) {
            if (!pq1.empty() && !pq2.empty()) {
                if (pq1.top() > pq2.top()) {
                    cost += pq2.top() ;
                    pq2.pop();
                    if (!remain.empty()) {
                        pq2.push(remain.back());
                        remain.pop_back();
                    }
                }
                else {
                    cost += pq1.top() ;
                    pq1.pop();
                    if (!remain.empty()) {
                        pq1.push(remain.front());
                        remain.pop_front();
                    }
                }
            }
            else if (!pq1.empty()) {
                cost += pq1.top() ;
                pq1.pop();
                if (!remain.empty()) {
                    pq1.push(remain.front());
                    remain.pop_front();
                }
            }
            else {
                cost += pq2.top() ;
                pq2.pop();
                if (!remain.empty()) {
                    pq2.push(remain.front());
                    remain.pop_front();
                }
            }
        }
        return cost ; 
    }
};