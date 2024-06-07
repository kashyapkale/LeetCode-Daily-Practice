class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict;
        for(string word : dictionary){
            dict.insert(word);
        }

        int len_sentance = sentence.length();
        string temp = "";
        string ans;
        bool isReplaceable = false;
        for(int i = 0; i < len_sentance; i++){
            if(sentence[i] == ' '){
                if(isReplaceable){
                    isReplaceable = false;
                } else{
                    ans+=temp;
                    temp = "";
                }
                ans+=" ";
            } else if(!isReplaceable){
                temp += sentence[i];
                if(dict.find(temp) != dict.end() || i == len_sentance - 1){
                    ans+=temp;
                    temp = "";
                    isReplaceable = true;
                }
            }
        }

        return ans;
    }
};