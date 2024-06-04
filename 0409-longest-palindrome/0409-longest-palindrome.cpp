class Solution {
public:
    int longestPalindrome(string s) {
        int lower_case_arr[26] = {0};
        int upper_case_arr[26] = {0};
        for(char ch : s){
            if(ch >= 'a' && ch <= 'z'){
                lower_case_arr[ch-'a']++;
            } else{
                upper_case_arr[ch-'A']++;
            }
        }

        int total_left_over = 0;
        for(int i = 0; i < 26; i++){
            total_left_over += (lower_case_arr[i] % 2);
            total_left_over += (upper_case_arr[i] % 2);
        }

        int ans = 0;
        if(total_left_over == 0)
            ans += s.length();
        else
            ans += (s.length() - total_left_over + 1);
        
        return ans;
    }
};