class Solution {
public:
    int dr[8] = {0, 0, -1, 1, -1, -1, 1, 1};
    int dc[8] = {1, -1, 0, 0, -1, 1, -1, 1};

    int n , m ;
    vector<vector<int>> dis ;
    bool isBorder(int r,  int c) {
        return r == 0 || c == 0 || r == m - 1 || c == n - 1 ;
    }

    bool isValid(int r , int c) {
        return r >= 0 && c >= 0 & r < m && c < n ;
    }

    void BFS(int i , int j , vector<vector<char>>& maze) {
        queue<pair<int , int>> q ;
        dis.resize(m , vector<int>(n,1e9));

        q.push({i ,j});
        dis[i][j] = 0 ;

        while (!q.empty()) {
            auto [r , c] = q.front() ;
            q.pop();

            for (int d = 0 ; d < 4 ; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (!isValid(nr, nc) || maze[nr][nc] == '+')
                    continue;

                if (dis[nr][nc] > dis[r][c] + 1) {
                    dis[nr][nc] = dis[r][c] + 1 ;
                    q.push({nr, nc});
                }
            }
        }
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size() ;
        n = maze[0].size();
        BFS(entrance[0] , entrance[1] , maze);

        int ans = 1e9 ;
        for (int r = 0 ; r < m ; r++) {
            for (int c = 0 ; c < n ; c++) {
                if (isBorder(r ,c) && dis[r][c] != 1e9 && dis[r][c] != 0)
                    ans = min(ans , dis[r][c]);
            }
        }

        if (ans == 1e9)
            return -1;
        return ans ;
    }
};