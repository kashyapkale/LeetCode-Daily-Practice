class Solution {
public:
    int appendCharacters(string s, string t) {
        int N = s.length();
        int M = t.length();
        int i = 0;
        int j = 0;
        while(i < N && j < M){
            if(s[i] == t[j]){
                j++;
            }

            i++;
        }

        return M - j;
    }
};