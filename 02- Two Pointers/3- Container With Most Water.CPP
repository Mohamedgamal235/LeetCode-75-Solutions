class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        int l = 0 , r = n - 1 ;
        int maxi = INT_MIN ; 
        while (l < r) {
            int curr = min(height[l] , height[r]) * (r - l);
            maxi= max(maxi , curr);
            if (height[l] > height[r])
                r-- ;
            else
                l++ ; 
        }
        return maxi ; 
    }
};