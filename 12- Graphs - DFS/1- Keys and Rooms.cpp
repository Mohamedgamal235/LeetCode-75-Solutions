class Solution {
public:
    vector<vector<int>> adjList ;
    vector<bool> visited ;
    void DFS(int node) {
        visited[node] = true ;
        for (auto it : adjList[node]) {
            if(!visited[it])
                DFS(it);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size() ;
        visited.resize(n);
        adjList.resize(n) ;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < rooms[i].size() ; j++) {
                adjList[i].push_back(rooms[i][j]);
            }
        }

        int components = 0 ;
        for (int i = 0 ; i < n ; i++) {
            if (!visited[i]) {
                DFS(i);
                components++;
            }
        }
        return components == 1 ;
    }
};