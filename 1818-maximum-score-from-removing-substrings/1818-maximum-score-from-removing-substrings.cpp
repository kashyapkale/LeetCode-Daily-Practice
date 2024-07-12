class Solution {
private:
    int calculate_points(string &s, string sub_s){
        stack<char> st;
        string temp = "";
        int str_count = 0;
        for(char ch : s){
            if(st.empty()){
                st.push(ch);
            } else {
                char top = st.top();
                if(ch == sub_s[1] && top == sub_s[0]){
                    st.pop();
                    str_count++;
                } else{
                    st.push(ch);
                }
            }
        }

        while(!st.empty()){
            temp += st.top();
            st.pop();
        }

        s = temp;
        return str_count;
    }
public:
    int maximumGain(string s, int x, int y) {
        string max_str = (x > y) ? "ab" : "ba";
        string min_str = (x < y) ? "ab" : "ba";
        int max_points = (x > y) ? x : y;
        int min_points = (x < y) ? x : y;
        int ans = 0;
        ans += (calculate_points(s, max_str) * max_points);
        reverse(s.begin(), s.end());
        ans += (calculate_points(s, min_str) * min_points); 
        return ans;
    }
};