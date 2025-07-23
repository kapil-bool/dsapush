class Solution {
public:
    int maximumGain(string s, int x, int y) {
        //so here u should try removing the one with more priority as here ba then the remaing letter to be seen and 
        //see for all ab  possiblites 
        //stack implemntation top and second one;
        //here chose the one with higer priorty first x=ab and y=ba;
        //first the priorty and then the do the check and remove accordinly

        //1. priorties
        
        int ans = 0;
        string highPriorityPair = (x > y) ? "ab" : "ba";
        string lowPriorityPair = (x > y) ? "ba" : "ab";
        int highScore = max(x, y);
        int lowScore = min(x, y);

        // First Pass: Remove high priority pairs
        stack<char> st;
        string rem;
        for (char c : s) {
            if (!st.empty() && st.top() == highPriorityPair[0] && c == highPriorityPair[1]) {
                st.pop();
                ans += highScore;
            } else {
                st.push(c);
            }
        }

        // Build the remaining string from stack
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());

        // Second Pass: Remove low priority pairs from remaining string
        for (char c : rem) {
            if (!st.empty() && st.top() == lowPriorityPair[0] && c == lowPriorityPair[1]) {
                st.pop();
                ans += lowScore;
            } else {
                st.push(c);
            }
        }

        return ans;
    }
};