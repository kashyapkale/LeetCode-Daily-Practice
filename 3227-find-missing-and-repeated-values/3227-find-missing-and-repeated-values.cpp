class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int N = grid.size();
        int a,b;
        vector<int> freq((N*N)+1, 0);
        for(vector<int> vec : grid){
            for(int it : vec){
                if(freq[it] == 0)
                    freq[it]++;
                else if(freq[it] > 0){
                    freq[it]++;
                    a = it;
                }
            }
        }

        for(int i = 1;i <= N*N; i++){
            if(freq[i] == 0){
                b = i;
                break;
            }
        }

        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};