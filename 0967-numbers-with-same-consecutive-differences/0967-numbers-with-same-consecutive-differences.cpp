class Solution {
private:
    void dfs(vector<int> &ans, int source, int n, int k){
        if(n == 0){
            ans.push_back(source);
            return;
        }

        int lastDigit = source % 10;
        if(lastDigit+k <= 9){
            dfs(ans, (source*10)+(lastDigit+k), n-1, k);
        }

        if(k!=0 && lastDigit-k >= 0){
            dfs(ans, (source*10)+(lastDigit-k), n-1, k);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++){
            dfs(ans, i, n-1, k);
        }
        return ans;
    }
};