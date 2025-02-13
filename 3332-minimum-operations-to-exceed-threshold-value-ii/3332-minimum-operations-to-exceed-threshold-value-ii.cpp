class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Creating a priority queue to act as a min heap
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(auto it : nums){
            minHeap.push(it);
        }
        
        int ans = 0;
        while(minHeap.top() < k && minHeap.size() >= 2){
                long long top1 = minHeap.top();
                minHeap.pop();
                long long top2 = minHeap.top();
                minHeap.pop();
                minHeap.push((top1*2)+top2);
                ans++;
            }
        
        return ans;
    }
};