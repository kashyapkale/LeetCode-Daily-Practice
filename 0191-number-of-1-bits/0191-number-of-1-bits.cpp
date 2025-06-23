class Solution {
public:
    int hammingWeight(int n) {
        int bitLength = sizeof(int) * CHAR_BIT;
        int ans = 0;
        for (int i = bitLength - 1; i >= 0; --i) {
            if(((n >> i) & 1) == 1){
                ans++;
            }    
        }
        
        return ans;
    }
};