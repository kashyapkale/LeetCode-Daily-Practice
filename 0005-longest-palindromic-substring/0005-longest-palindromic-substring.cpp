class Solution {
private:
    pair<int, int> getSubstrIndex(int left, int right, string &s){
        int len = s.length();

        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }

        return make_pair(left + 1, right - 1);
    }

public:
    string longestPalindrome(string s) {
            int len = s.length();
            if(len == 0){
                return "";
            }
            int max_len = 1;
            pair<int, int> maxSubStrIndex = make_pair(0, 0);
            for(int i = 0; i < len - 1; i++){
                //Odd Length check
                pair<int, int> subStrIndexOdd = getSubstrIndex(i, i, s);
                if((subStrIndexOdd.second - subStrIndexOdd.first) 
                        > (maxSubStrIndex.second - maxSubStrIndex.first)){
                        maxSubStrIndex.first = subStrIndexOdd.first;
                        maxSubStrIndex.second = subStrIndexOdd.second;
                }

                //Even Length check
                pair<int, int> subStrIndexEven = getSubstrIndex(i, i+1, s);
                if((subStrIndexEven.second - subStrIndexEven.first) 
                        > (maxSubStrIndex.second - maxSubStrIndex.first)){
                        maxSubStrIndex.first = subStrIndexEven.first;
                        maxSubStrIndex.second = subStrIndexEven.second;
                }
            }

            return s.substr(maxSubStrIndex.first, maxSubStrIndex.second - maxSubStrIndex.first + 1);
    }
};