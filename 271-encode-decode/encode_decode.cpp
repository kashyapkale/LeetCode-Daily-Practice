class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0){
            return "NULL";
        }
        for(string s : strs){
            int index = 0;
            bool isEmojiOn = false;
            int emojiStartIndex;
            int emojiEndIndex;
            for(char ch : s){
                    if(ch < 0 || ch > 127){
                        if(!isEmojiOn){
                            emojiStartIndex = index;
                            ans+=';';
                        }
                        isEmojiOn = true;
                    } else {
                        if(isEmojiOn){
                            emojiEndIndex = index;
                            isEmojiOn = false;
                            ans+=s.substr(emojiStartIndex, emojiEndIndex - emojiStartIndex);
                            ans+=';';
                        }
                        int ascii_val = ch;
                        ans += to_string(ascii_val);
                    }
                    index++;
                    if(!isEmojiOn){
                        ans += ',';
                    }
            }

            if(isEmojiOn){
                emojiEndIndex = index;
                isEmojiOn = false;
                ans+=s.substr(emojiStartIndex, emojiEndIndex - emojiStartIndex);
                ans+=';';
                ans+=',';
            }
            int curr_len = ans.length();
            if(curr_len != 0)
                ans[curr_len - 1] = ':';
            else{
                ans += ':';
            }
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp = "";
        
        if(s == "NULL"){
            return ans;
        }
        if(s == ""){
            ans.push_back(s);
        }

        int ascii_str = 0;
        bool isEmojiOn = false;
        int emojiStartIndex;
        int emojiEndIndex;
        int index = 0;
        for(char ch : s){
            if(ch == ':'){
                if(ascii_str != 0){
                    temp += (char)ascii_str;
                }
                ans.push_back(temp);
                ascii_str = 0;
                temp = ""; 
            } else if(ch == ','){
                temp += (char)ascii_str;
                ascii_str = 0;
            } else if(ch == ';'){
                if(!isEmojiOn){
                    isEmojiOn = true;
                    emojiStartIndex = index+1;
                } else{
                    isEmojiOn = false;
                    emojiEndIndex = index;
                    string m = s.substr(emojiStartIndex, emojiEndIndex - emojiStartIndex);
                    temp += m;
                }
            } else if(!isEmojiOn){
                ascii_str *= 10;
                string t = "";
                t+=ch;
                ascii_str += stoi(t);
            }
            index++;
        }

        return ans;
    }
};
