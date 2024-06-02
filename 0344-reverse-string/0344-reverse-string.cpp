class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int N = s.size();
        int j = N - 1;
        while(i <= j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};