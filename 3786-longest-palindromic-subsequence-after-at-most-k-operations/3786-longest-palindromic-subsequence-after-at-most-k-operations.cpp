class Solution {
private:
    int minForReplacement(int low, int high, const string& s){
        return min(abs(s[low] - s[high]), 26 - abs(s[low] - s[high]));
    }

    int lps(const string& s, int low, int high, 
                        vector<vector<vector<int>>> &dp, int k) {
    if(low > high) return 0;
  
    if (low == high)
        return 1;

    if(dp[low][high][k] != -1) 
        return dp[low][high][k];

        
    int maxLength = 0;

        if (s[low] == s[high]) {
            maxLength = lps(s, low + 1, high - 1, dp, k) + 2;
        } else {
            int requiredK = minForReplacement(low, high, s);
            if (k >= requiredK) {
                maxLength = max(maxLength, 2 + lps(s, low + 1, high - 1, dp, k - requiredK));
            }
        }

        
        maxLength = max(maxLength, lps(s, low + 1, high, dp, k));
        maxLength = max(maxLength, lps(s, low, high - 1, dp, k));

        return dp[low][high][k] = maxLength;
}
public:
    int longestPalindromicSubsequence(string s, int k) {
        int len = s.length();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>> (len + 1, vector<int>(k + 1, -1)));
        int high = len - 1;
        int low = 0;
        return lps(s, low, high, dp, k);
    }
};