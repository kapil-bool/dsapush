class Solution {
public:
    // helper function to calculate max area in histogram
    int areahelper(vector<int> heights){
        int n = heights.size();                
        int maxarea = 0;
        stack<int> st;

        // traverse till n (sentinel logic)
        for(int i = 0; i <= n; i++){
            int current = (i == n ? 0 : heights[i]);  
        // now iske respect me both end will be explored ;
            // left and right boundary handled here
            while(!st.empty() && current < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();   // previous smaller
                int b = i - left - 1;                    // width
                maxarea = max(maxarea, h * b);          
            }
            st.push(i);   
        }
        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        // histogram like pattern row wise plot karo and u see the pattern here 
        // dp[i][j];

        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        // now row wise travesal karo and a histogram is created here
        // + if not 0 (prev) add else reset
        vector<int> heights(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1')
                    heights[j]++;        // correct index
                else{
                    heights[j] = 0;      // break condition
                }
            }

            // here calculate the greatest till now 
            // width + height handled by monotonic stack
            ans = max(ans, areahelper(heights));
        }
        return ans;
    }
};
