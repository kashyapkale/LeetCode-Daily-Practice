class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int len = nums.size();
        vector<int> ans(len);
        int left = 0;
        int right = len - 1;
        
        for(int num : nums){
            if(num < pivot){
                ans[left] = num;
                left++;
            } else if(num > pivot){
                ans[right] = num;
                right--;
            } 
        }

        while(left <= right){
            ans[left] = pivot;
            left++;
        }

        reverse(ans.begin()+right+1, ans.end());
        return ans;
    }
};