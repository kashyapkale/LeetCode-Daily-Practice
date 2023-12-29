class Solution {
private:
    void dfs(int source, int n, vector<vector<int>>& isConnected, vector<bool> &visited){
        visited[source] = true;
        for(int i = 0; i < n; i++){
            if(!visited[i] && isConnected[source][i] == 1){
                dfs(i, n, isConnected, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int connectedComponents = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                connectedComponents++;
                dfs(i, n, isConnected, visited);
            }
        }

        return connectedComponents;
    }
};