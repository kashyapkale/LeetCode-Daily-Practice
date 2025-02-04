class Solution {
private:
    int changeUtil(int amount, vector<int> &coins, int index, vector<vector<int>> &dp){
        int len = coins.size();
        if(index == len){
            if(amount == 0){
                return 1;
            } else {
                return 0;
            }
        }

        if(dp[amount][index] != -1){
            return dp[amount][index];
        }

        //pick
        int pick = 0;
        if(amount - coins[index] >= 0){
            pick = changeUtil(amount - coins[index], coins, index, dp);
        }
        
        //not pick
        int notPick = changeUtil(amount, coins, index+1, dp);

        return dp[amount][index] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, -1));
        return changeUtil(amount, coins, 0, dp);
    }
};