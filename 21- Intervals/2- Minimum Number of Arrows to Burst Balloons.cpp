class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end() , [](vector<int>&a , vector<int>&b) {
            return a[1] < b[1];
        });
        int ans = 1 ;
        int prevEnd = points[0][1];
        for (int i = 1 ; i < points.size() ; i++) {
            if (prevEnd < points[i][0]) {
                prevEnd = points[i][1] ;
                ans++ ; 
            }
        }
        return ans;
    }
};