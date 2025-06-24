class Solution {
public:
    int longestValidParentheses(string s) {
        //use stack push indexded here for  evert (  and pop ) maintain the lenght claulate elenght with this help and also is  empty and ) then handel this case also
     stack<int> st;
        int lastUnmatched = -1;
        int len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    st.pop(); // matched with a '('
                    if (!st.empty()) {
                        len = max(len, i - st.top());
                    } else {
                        len = max(len, i - lastUnmatched);
                    }
                } else {
                    // unmatched ')', set new base
                    lastUnmatched = i;
                }
            }
        }

        return len;
    }
};