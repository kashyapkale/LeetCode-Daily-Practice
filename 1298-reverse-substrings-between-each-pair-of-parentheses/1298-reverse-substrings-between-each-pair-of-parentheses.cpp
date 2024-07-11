class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<int> op;
        int index = 0;
        for(char ch : s){
            if(ch == '('){
                op.push(ans.length());
            } else if(ch == ')'){
                int top_index = op.top();
                op.pop();
                reverse(ans.begin() + top_index, ans.end());
            } else {
                ans += ch;
            } 
            
            index++;
        }

        return ans;
    }
};