class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                default:
                    if (st.empty()) return false;
                    char top = st.top();
                    int diff = ch - top;
                    if (diff == 1 || diff == 2) {
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
            }
        }
        return st.empty();
    }
};