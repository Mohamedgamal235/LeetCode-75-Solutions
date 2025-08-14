class Solution {
public:

    struct edge {
        int to ;
        bool built ;
    };

    void DFS(vector<vector<edge>>& adjList , int node , vector<bool>& visited , int &ans) {
        visited[node] = true ;

        for (auto &e : adjList[node]) {
            if (!visited[e.to]) {
                ans += e.built ;
                DFS(adjList , e.to , visited , ans) ;
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<edge>> adjList(n) ;
        int ans = 0 ;
        vector<bool> visited(n) ;

        for (auto e : connections) {
            adjList[e[0]].push_back({e[1] , true }) ;
            adjList[e[1]].push_back({e[0] , false });
        }

        DFS(adjList , 0 , visited , ans) ;
        return ans ;
    }
};