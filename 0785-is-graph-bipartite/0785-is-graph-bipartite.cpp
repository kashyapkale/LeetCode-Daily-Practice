//-1 - not visited
//0 - white
//1 - black

class Solution {
private:
    int invert(int it){
        return (it == 0) ? 1 : 0;
    }


    bool bfs(vector<vector<int>>& graph, vector<int>& color, int index){
        queue<int> bfsQ;
        color[index] = 0;
        bfsQ.push(index);

        while(!bfsQ.empty()){
            int top_elem = bfsQ.front();
            bfsQ.pop();
            for(int it : graph[top_elem]){
                if(color[it] == -1){
                    color[it] = invert(color[top_elem]);
                    bfsQ.push(it);
                } else if(color[it] == color[top_elem]){
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> color(len, -1);
        for(int i = 0; i < len; i++){
            if(color[i] == -1 && !bfs(graph, color, i)){
                return false;
            }
        }
        return true;
    }
};