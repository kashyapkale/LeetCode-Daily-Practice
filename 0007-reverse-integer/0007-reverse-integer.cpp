class Solution {
public:
    int reverse(int x) {
        bool isInitialNegative = (x < 0);
        int range = INT_MAX/10;
        int ans = 0;

        if(x == INT_MIN || x == INT_MAX){
            return 0;
        }

        x = abs(x);
        while(x){
            if(ans > range)
                return 0;

            ans = ans * 10;
            ans += (x % 10);
            x = x / 10;
        }

        if(isInitialNegative)
            return ans * -1;
        
        return ans;
    }
};