class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            // Opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Closing brackets
            else {
                // No opening bracket available
                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                // Check whether brackets match
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Stack should be empty if every bracket matched
        return st.empty();
    }
};