class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int len = blocks.length();
        int ans = INT_MAX;
        for(int i = 0; i <= len - k; i++){
            int current_steps = 0;
            int black_boxes = 0;
            for(int j = i; j < i + k; j++){
                if(blocks[j] == 'W'){
                    current_steps++;
                    black_boxes = 0;
                } else{
                    black_boxes++;
                }
                if(black_boxes >= k){
                    return 0;
                }
            }
            ans = min(ans, current_steps);
        }
        return ans;
    }
};