/*class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int len = nums.size();
        vector<int> prevMax(len);
        vector<int> nextMax(len);

        int currMax = 0;
        int nextCurrMax = 0;
        for(int i = 0; i < len; i++){
            prevMax.push_back(currMax);
            cout<<currMax<<" ";
            currMax = max(currMax, nums[i]);
        }
        cout<<endl;
        
        for(int i = len - 1; i >= 0; i--){
            nextMax[i] = nextCurrMax;
            cout<<nextCurrMax<<" ";
            nextCurrMax = max(nextCurrMax, nums[i]);
        }

        cout<<endl;
        int ans = 0;
        for(int i = 0; i < len; i++){
            ans = max(ans, (prevMax[i] - nums[i]) * nextMax[i]);

            cout<< ans << " " << prevMax[i] << " " << nextMax[i] << endl;
        }

        return ans;
    }
};*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i+1]);
        }

        long long result = 0;
        for (int j = 1; j < n - 1; j++) {
            result = max(result, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return result;
    }
};