class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int index1 = 0;
        int index2 = 0;
        int len1 = word1.length();
        int len2 = word2.length();
        while(index1 < len1 && index2 < len2){
            ans += word1[index1];
            ans += word2[index2];
            index1++;
            index2++;
        }
        

        while(index1 < len1){
            ans += word1[index1];
            index1++;
        }

        while(index2 < len2){
            ans += word2[index2];
            index2++;
        }

        return ans;
    }
};