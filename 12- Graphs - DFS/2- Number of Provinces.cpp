class Solution {
    public:
    
        void DFS(int node , vector<vector<int>>& adjList , vector<bool>& visited) {
            visited[node] = true ;
    
            for (auto neighbours : adjList[node]) {
                if (!visited[neighbours]) {
                    DFS(neighbours , adjList , visited) ; 
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size() ;
            vector<vector<int>> adjList(n) ;
            vector<bool> visited(n , false); 
    
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < n ;j++) {
                    if (isConnected[i][j] == 1) {
                        adjList[i].push_back(j);
                        adjList[j].push_back(i);
                    }
                }
            }
    
            int com = 0 ;
            for (int i = 0 ; i < n ; i++) {
                if (!visited[i]) {
                    DFS(i , adjList , visited) ;
                    com++ ;
                }
            }
    
            return com ; 
        }
    };