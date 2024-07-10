class Solution {
public:
    int minOperations(vector<string>& logs) {
        int current_count = 0;
        for(string &log : logs){
            if(log == "../" && current_count > 0){
                current_count--;
            } else if(log != "../" && log != "./"){
                current_count++;
            }
        }

        return current_count;
    }
};