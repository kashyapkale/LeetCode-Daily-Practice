class Solution {
public:
    string multiply(string num1, string num2) {
        long len1 = num1.length();
        long len2 = num2.length();
        string inp1;
        long long inp1_len;
        string inp2;
        long long inp2_len;
        vector<int> vec_ans(len1 + len2 + 1, 0);
        if(len1 > len2){
            inp1 = num1;
            inp2 = num2;
            inp1_len = len1;
            inp2_len = len2;
        } else {
            inp1 = num2;
            inp2 = num1;
            inp1_len = len2;
            inp2_len = len1;
        }
        

        int total_len = len1+len2;
        int sum = 0;
        int index = 0;
        int buffer = 0;
        for(int i = inp2_len - 1; i >= 0; i--){
            int step_sum = 0;
            int carry = 0;
            int fix_digit = inp2[i] - '0';
            int inner_index = 0;
            for(int j = inp1_len - 1; j >= 0; j--){
                int vec_index = (total_len) - inner_index - buffer;
                int multiply_digit = inp1[j] - '0';
                int current_product = vec_ans[vec_index] + (fix_digit * multiply_digit);
                carry = current_product / 10;
                int digit_to_add = current_product % 10;
                vec_ans[vec_index] = digit_to_add;
                vec_ans[vec_index-1] += carry;
                inner_index++;
            }
            buffer++;
            index++;
        }

        string ans = "";
        bool isAnsStarting = false;
        for(int i : vec_ans){
            if(i != 0){
                isAnsStarting = true;
            }
            if(isAnsStarting){
                ans += to_string(i);
            }
        }

        return (ans == "") ? "0" : ans;
    }
};