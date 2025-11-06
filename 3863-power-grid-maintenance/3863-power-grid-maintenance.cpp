

class Solution {
private:

    vector<int> parent;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j; 
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        parent.resize(c + 1);
        iota(parent.begin(), parent.end(), 0); 

        for (const auto& conn : connections) {
            unite(conn[0], conn[1]);
        }

        vector<bool> is_online(c + 1, true);

        map<int, set<int>> online_nodes_in_component;
        for (int i = 1; i <= c; ++i) {

            online_nodes_in_component[find(i)].insert(i);
        }

        vector<int> results;

        for (const auto& query : queries) {
            int type = query[0];
            int x = query[1];

            if (type == 1) {

                if (is_online[x]) {

                    results.push_back(x);
                } else {

                    int root = find(x);
                    auto& online_set = online_nodes_in_component[root];

                    if (online_set.empty()) {

                        results.push_back(-1);
                    } else {

                        results.push_back(*online_set.begin());
                    }
                }
            } else {

                if (is_online[x]) {

                    is_online[x] = false;

                    int root = find(x);

                    online_nodes_in_component[root].erase(x);
                }
            }
        }

        return results;
    }
};