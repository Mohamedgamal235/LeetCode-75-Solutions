public class Solution {

    public void DFS(int node , List<List<int>> adjList , bool[] visited){
        visited[node] = true ; 
        foreach(var neighbour in adjList[node]){
            if (!visited[neighbour])
                DFS(neighbour , adjList , visited);
        }
    }
    public int FindCircleNum(int[][] isConnected) {
        int n = isConnected.Length ; 
        List<List<int>> adjList = new List<List<int>>(n);
        bool[] visited = new bool[n] ;

        for (int i = 0 ; i < n ; i++)
            adjList.Add(new List<int>());

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if (isConnected[i][j] == 1){
                    adjList[i].Add(j);
                    adjList[j].Add(i);
                }
            }
        }

        int ans = 0 ; 
        for (int i = 0 ; i < n ; i++){
            if (!visited[i]){
                DFS(i , adjList , visited) ; 
                ans++ ; 
            }
        }

        return ans ; 
    }
}