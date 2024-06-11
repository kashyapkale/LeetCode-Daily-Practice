class Solution {
private:
    int maxTotalRewardUtil(vector<int>& rewardValues, int index, int value, vector<vector<int>> &dp) {
        int N = rewardValues.size();
        if(N == index){
            return value;
        }
        
        if(dp[index][value] != -1){
            return dp[index][value];
        }
        
        int pick = 0;
        if(rewardValues[index] > value){
           pick = maxTotalRewardUtil(rewardValues, index + 1, value + rewardValues[index], dp); 
        }
        
        //not pick
        int notPick = maxTotalRewardUtil(rewardValues, index + 1, value, dp); 
        return dp[index][value] = max(pick, notPick);
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        vector<vector<int>> dp(rewardValues.size(), vector<int>(4000, -1));
        int value = 0;
        return maxTotalRewardUtil(rewardValues, 0, value, dp);
    }
};