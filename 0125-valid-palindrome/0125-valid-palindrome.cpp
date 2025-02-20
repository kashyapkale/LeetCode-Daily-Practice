class Solution {
private:
    bool isCharAlphaNumeric(char ch){
        return (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122);
    }
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int left = 0;
        int right = len - 1;

        while(left <= right){
            while(left < len && !isCharAlphaNumeric(s[left])){
                left++;
            }

            while(right >= 0 && !isCharAlphaNumeric(s[right])){
                right--;
            }

            if(left < len && right >= 0 && tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};