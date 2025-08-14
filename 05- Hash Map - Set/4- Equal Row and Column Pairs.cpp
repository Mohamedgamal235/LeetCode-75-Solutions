class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size() ;
        map<vector<int> , int> freq ;
        
        for (int r = 0 ; r < n ; r++) {
            vector<int> rows ;
            for (int c = 0 ; c < n ; c++) 
                rows.push_back(grid[r][c]);
            freq[rows]++ ; 
        }

        int ans = 0 ;
        for (int c = 0 ; c < n ; c++) {
            vector<int> cols ;
            for (int r = 0 ; r < n ; r++) 
                cols.push_back(grid[r][c]);
            ans += freq[cols];
        }
        return ans ; 
    }
};