class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int ans_count = 0;
        for(int i : arr){
            if(i % 2 != 0){
                ans_count++;
            } else {
                ans_count = 0;
            }

            if(ans_count == 3){
                return true;
            }
        }

        return false;
    }
};