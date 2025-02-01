class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        bool isLastBitEven = (nums[0] % 2) ? true : false; 
        for(int i = 1; i < n; i++){
            bool isCurrentBitEven = (nums[i] % 2) ? true : false; 
            if((isCurrentBitEven && isLastBitEven) || (!isCurrentBitEven && !isLastBitEven))
                return false;
            isLastBitEven = isCurrentBitEven;
        }

        return true;
    }
};