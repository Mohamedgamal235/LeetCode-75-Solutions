class Solution {
public:
    unordered_map<string , unordered_map<string , double>> adjList ;
    void DFS(string node , string dest , double &ans , double val , unordered_set<string> &vis) {
        if (vis.find(node) != vis.end()) return;
        vis.insert(node);
        if (node == dest) {
            ans = val ;
            return;
        }
        for (auto neighbour : adjList[node])
            DFS(neighbour.first , dest , ans , val * neighbour.second , vis);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0 ; i < equations.size() ; i++) {
            string x = equations[i][0];
            string y = equations[i][1];
            adjList[x][y] = values[i];
            adjList[y][x] = 1 / values[i];
        }

        int q = queries.size();
        vector<double> res ;
        for (int i = 0 ; i < q ; i++) {
            string x = queries[i][0];
            string y = queries[i][1];

            if (adjList.find(x) == adjList.end() || adjList.find(y) == adjList.end())
                res.push_back(-1.00000);
            else {
                unordered_set<string> vis ;
                double ans = -1.00000 , val = 1.00000 ;
                DFS(x , y , ans , val , vis);
                res.push_back(ans);
            }

        }
        return res ;
    }
};