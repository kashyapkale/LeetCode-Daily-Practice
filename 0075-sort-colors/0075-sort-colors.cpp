class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sizeOfNums = nums.size();
        int high = sizeOfNums-1;
        int low = 0;
        int mid = 0;
        while(high >= mid && mid<sizeOfNums){
            if(nums[mid] == 1) {
                mid++;
                continue;
            }

            if(nums[mid] == 2){
                while(nums[mid] == 2 && mid != high) {
                    swap(nums[mid], nums[high]);
                    high--;
                }
            }

            if(nums[mid] == 0){
                while(nums[mid] == 0 && mid != low) {
                    swap(nums[mid], nums[low]);
                    low++;
                }
            }

            mid++;

        }    
    }
};