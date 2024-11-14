class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;    
        
        int ans = INT_MIN;
        while(left < right){
            int currHeight = min(height[left], height[right]);
            int width = right - left;
            ans = max(ans, currHeight * width);

            if(height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        }

        return ans;  
    }
};