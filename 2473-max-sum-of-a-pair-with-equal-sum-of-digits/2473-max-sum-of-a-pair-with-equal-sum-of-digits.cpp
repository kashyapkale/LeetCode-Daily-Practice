class Solution {
private:
    int sumOfDigits(int num){
        int sum = 0;
        while(num){
            sum+=(num%10);
            num = num/10;
        }

        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> umap;
        int max_sum = -1;
        for(int i = 0; i < len; i++){
            int currentSumOfDigits = sumOfDigits(nums[i]);
            if(umap.find(currentSumOfDigits) != umap.end()){
                int curr_sum = nums[umap[currentSumOfDigits]] + nums[i];
                max_sum = max(max_sum, curr_sum);
                if(nums[umap[currentSumOfDigits]] < nums[i]){
                    umap[currentSumOfDigits] = i;
                }
            } else{
                umap[currentSumOfDigits] = i;
            }
        }

        return max_sum;
    }
};