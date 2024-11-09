class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int left = 0;

        if(len == 1 || len == 0){
            return len;
        }

        unordered_set<char> char_set;
        int longest_substring = 1;
        

        for(int right = 0; right < len; right++){
            while(char_set.find(s[right]) != char_set.end()){
                char_set.erase(s[left]);
                left++;
            }

            char_set.insert(s[right]);
            longest_substring = max(right-left+1, longest_substring);
        }

        return longest_substring;
    }
};