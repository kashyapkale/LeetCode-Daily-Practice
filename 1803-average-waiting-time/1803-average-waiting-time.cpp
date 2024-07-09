class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int instance = 0;
        double N = customers.size();
        double total = 0;
        for(vector<int> &customer : customers){
            instance = (max(instance, customer[0]) + customer[1]);
            total += (instance - customer[0]);
        }

        return (total / N);
    }
};