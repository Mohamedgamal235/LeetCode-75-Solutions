class Solution {
public:
    int dr[8] = {0, 0, -1, 1, -1, -1, 1, 1};
    int dc[8] = {1, -1, 0, 0, -1, 1, -1, 1};


    bool isValid(int r , int c , vector<vector<int>>& grid) {
        return r < grid.size() && c < grid[0].size() && r >= 0 && c >= 0 && grid[r][c] == 1;
    }

    int BFS(vector<vector<int>>& grid) {
        queue<pair<int ,int>> q ;
        set<pair<int , int>> vis ;

        for (int r = 0 ; r < grid.size() ; r++)
            for (int c = 0 ; c < grid[r].size() ; c++)
                if (grid[r][c] == 2)
                    q.push({r,c});

        int maxLevel = 0 ;
        while (!q.empty()) {
            int level = q.size() ;
            for (int i = 0 ; i < level ; i++) {
                auto [r ,c] = q.front() ;
                q.pop();
                for (int d = 0 ; d < 4 ; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(!isValid(nr ,nc ,grid) || vis.find({nr,nc}) != vis.end())
                        continue;
                    grid[nr][nc] = 2 ;
                    q.push({nr,nc});
                }
            }
            if (!q.empty())
                maxLevel++ ;
        }
        return maxLevel ;
    }

    int countFresh(vector<vector<int>>& grid) {
        int fresh = 0 ;
        for (int r = 0 ; r < grid.size() ; r++)
            for (int c = 0 ; c < grid[r].size() ; c++)
                if (grid[r][c] == 1)
                    fresh++ ;
        return fresh;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        if (countFresh(grid) == 0)
            return 0;

        int ans = BFS(grid);
        int fresh = countFresh(grid);
        if (fresh)
            return -1 ;
        return ans ;
    }
};