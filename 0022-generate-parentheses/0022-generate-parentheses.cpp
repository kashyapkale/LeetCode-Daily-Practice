class Solution {
private:

    bool isStringValid(string s){
        stack<char> st;
        if(s[0] == ')'){
            return false;
        }

        for(char ch : s){
            if(st.empty()){
                st.push(ch);
            } else {
                if(ch == ')' && st.top() == '('){
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
        }

        return st.empty();
    }

    void generateParenthesisUtil(int openingBracket, int closingBracket, string currentItr, vector<string> &ans){
        if(openingBracket == 0 && closingBracket == 0 && isStringValid(currentItr)){
            ans.push_back(currentItr);
            return;
        } else if(openingBracket < 0 || closingBracket < 0){
            return;
        }

        if(openingBracket > 0){
            generateParenthesisUtil(openingBracket-1, closingBracket, currentItr+'(', ans);
        }

        if(closingBracket > 0){
            generateParenthesisUtil(openingBracket, closingBracket-1, currentItr+')', ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesisUtil(n, n, "", ans);
        return ans;
    }
};