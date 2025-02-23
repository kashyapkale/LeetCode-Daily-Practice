class Solution {
public:
    bool checkValidString(string s) {
        set<int> star_set;
        stack<int> st;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if((i == 0 || (st.empty() && star_set.empty())) 
                && s[i] == ')'){
                return false;
            }
            if(s[i] == '*'){
                star_set.insert(i);
                continue;
            } else if(st.empty()){
                st.push(i);
                continue;
            } else if(s[i] == ')' && s[st.top()] == '('){
                st.pop();
            } else{
                st.push(i);
            }
        }

        while(!st.empty()){
            int top = st.top();
            char bracket = s[top];
            if(bracket == ')') {
                auto it = star_set.upper_bound(top);
                if(it != star_set.begin()){
                    --it;
                    star_set.erase(it);
                } else{
                    return false;
                }
            } else if(bracket == '(') {
                auto it = star_set.lower_bound(top);
                if(it != star_set.end()){
                    star_set.erase(it);
                } else{
                    cout<<"3. ret false";
                    return false;
                }
            }

            st.pop();
        }

        return true;
    }
};