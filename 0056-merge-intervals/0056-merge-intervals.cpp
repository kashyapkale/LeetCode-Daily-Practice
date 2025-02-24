class Solution {
private:
const static bool intervals_comparator(vector<int> &A, vector<int> &B){
    return A[0] < B[0];
}

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int len = intervals.size();
        if(len < 2){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), intervals_comparator);
        int start;
        int end;
        for(int i = 0; i < len; i++){
            if(i == 0){
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }
            
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];
            if(current_start > end){
                ans.push_back({start, end});
                start = current_start;
                end = current_end;

                if(i == len - 1){
                    ans.push_back({start, end});
                }

                continue;
            }
            
            if(end >= current_start && end <= current_end){
                end = current_end;
            }

            if(i == len - 1){
                ans.push_back({start, end});
            }
        }
        return ans;
    }
};