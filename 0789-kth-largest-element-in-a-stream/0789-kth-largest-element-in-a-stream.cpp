class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k_;
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        min_heap.push(val);

        if(min_heap.size() > k_){
            min_heap.pop();
        }

        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */