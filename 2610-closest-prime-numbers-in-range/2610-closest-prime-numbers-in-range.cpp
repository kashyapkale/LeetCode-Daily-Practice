class Solution {
private:
    vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); 
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) { 
        if (isPrime[p]) { 
            for (int i = p * p; i <= n; i += p) { 
                isPrime[i] = false;
            }
        }
    }

    return isPrime;
}
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = sieveOfEratosthenes(right);
        int prev = INT_MIN;
        int prev_sum = INT_MAX;
        vector<int> ans(2, -1);
        for(int i = left; i <= right; i++){
            if(prev == INT_MIN){
                if(isPrime[i]){
                    prev = i;
                }
                continue;
            }
            if(isPrime[i]){
                int curr_sum = i - prev;
                if(curr_sum < prev_sum){
                    prev_sum = curr_sum;
                    ans[0] = prev;
                    ans[1] = i;
                }
                prev = i;
            }
        }

        return ans;
    }
};