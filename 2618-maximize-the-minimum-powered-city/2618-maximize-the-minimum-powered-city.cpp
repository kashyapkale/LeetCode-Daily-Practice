
class Solution {

bool check(long long target_power, int n, int r, long long k, const vector<long long>& initial_power) {

    vector<long long> additions(n, 0);

    long long k_used = 0;

    long long current_added_power = 0;

    for (int i = 0; i < n; ++i) {

        if (i > 0) {
            int entering_station = i + r;
            int leaving_station = i - r - 1;

            if (entering_station < n) {
                current_added_power += additions[entering_station];
            }
            if (leaving_station >= 0) {
                current_added_power -= additions[leaving_station];
            }
        } else {

            for (int j = 0; j <= min(n - 1, r); ++j) {
                current_added_power += additions[j]; 
            }
        }

        long long current_total_power = initial_power[i] + current_added_power;

        if (current_total_power < target_power) {
            long long needed = target_power - current_total_power;
            k_used += needed;

            if (k_used > k) {
                return false; 
            }

            int placement_city = min(n - 1, i + r);
            additions[placement_city] += needed;

            current_added_power += needed;
        }
    }

    return true;
}

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (long long)stations[i];
        }

        vector<long long> initial_power(n);
        long long min_power = -1;
        long long max_power = 0;

        for (int i = 0; i < n; ++i) {

            int l = max(0, i - r);
            int ri = min(n - 1, i + r);

            initial_power[i] = prefix[ri + 1] - prefix[l];

            if (min_power == -1 || initial_power[i] < min_power) {
                min_power = initial_power[i];
            }
            max_power = max(max_power, initial_power[i]);
        }

        long long low = min_power;
        long long high = max_power + k;
        long long ans = low;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, n, r, k, initial_power)) {

                ans = mid;
                low = mid + 1;
            } else {

                high = mid - 1;
            }
        }

        return ans;
    }
};