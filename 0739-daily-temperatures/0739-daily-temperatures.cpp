class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int days = temperatures.size();
        st.push(0);
        vector<int> ans(days, 0);
        for(int i = 1; i < days; i++){
            int temprature = temperatures[i];
            while(!st.empty() && temprature > temperatures[st.top()]){
                int top = st.top();
                ans[top] = i - top;
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};