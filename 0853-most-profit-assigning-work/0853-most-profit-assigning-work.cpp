class Solution {
private:
    static bool pair_comparator(pair<int, int> &p1, pair<int, int> &p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }

        return p1.first < p2.first;
    }

public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& workers) {
        vector<pair<int, int>> difficultyToProfitPairs;
        int N = difficulty.size();
        int current_profit = INT_MIN;
        for(int i = 0; i < N; i++){
            difficultyToProfitPairs.push_back(
                    make_pair(difficulty[i], profit[i])
                );
        }

        sort(difficultyToProfitPairs.begin(), difficultyToProfitPairs.end(), pair_comparator);
        for(int i = 0; i < N; i++){
            current_profit = max(difficultyToProfitPairs[i].second, current_profit);
            difficultyToProfitPairs[i].second = current_profit;
        }
        int ans = 0;
        for(int worker : workers){
            if(difficultyToProfitPairs[0].first <= worker){
                auto it = lower_bound(
                        difficultyToProfitPairs.begin(),
                        difficultyToProfitPairs.end(),
                        make_pair(worker, 0)
                    );
                if(it == difficultyToProfitPairs.end() || it->first != worker){
                    --it;
                } else {
                    /*while(((it+1 != difficultyToProfitPairs.end())) && (it+1)->first == it->first){
                        ++it;
                    }*/
                }
                ans += it->second;
            }
        }

        return ans;
    }
};