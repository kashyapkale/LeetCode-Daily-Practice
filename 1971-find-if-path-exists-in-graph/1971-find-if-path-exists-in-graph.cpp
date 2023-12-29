class Solution {
private:
    vector<vector<int>> adj;

    void createAdjList(int n, vector<vector<int>>& edges){
        adj.resize(n);
        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }


    bool bfs(int source, int destination, int n){
        vector<bool> visited(n, 0);
        queue<int> bfsQ;
        bfsQ.push(source);
        visited[source] = 1;
        while(!bfsQ.empty()){
            int head = bfsQ.front();
            bfsQ.pop();
            visited[head] = 1;
            if(head == destination){
                return true;
            }

            for(int &neighbour : adj[head]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    bfsQ.push(neighbour);
                }
            }
        }

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
              createAdjList(n, edges);
              return bfs(source, destination, n);
    }
};