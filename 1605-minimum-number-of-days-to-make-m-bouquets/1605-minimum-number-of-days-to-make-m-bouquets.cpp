class Solution {
private:
    bool isValidNum(vector<int>& bloomDay, int mid, int k, int m){
        int countOfBouquets = 0;
        int count = 0;
        int N = bloomDay.size();
        
        for (int i = 0; i < N; i++) {
            if (bloomDay[i] <= mid) {
                count++;
            } else {
                count = 0;
            }
            if (count == k) {
                countOfBouquets++;
                count = 0;
            }
        }
        return (countOfBouquets >= m);
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int N = bloomDay.size();
        int left = 0;
        int right = INT_MIN;
        for(int it : bloomDay){
            right = max(right, it);
        }

        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(isValidNum(bloomDay, mid, k, m)){
                ans = mid;
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }

        return ans;
    }
};