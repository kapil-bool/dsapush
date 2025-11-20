class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
          sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int p1 = -1;  // largest chosen point
        int p2 = -2;  // second largest chosen point
        int ans = 0;

        for (auto &it : intervals) {
            int L = it[0];
            int R = it[1];

            bool in1 = (p1 >= L && p1 <= R);
            bool in2 = (p2 >= L && p2 <= R);

            if (in1 && in2) {
               
                continue;
            }
            else if (in1) {
               
                ans += 1;
                p2 = p1;
                p1 = R;
            }
            else {
                
                ans += 2;
                p2 = R - 1;
                p1 = R;
            }
        }

        return ans;
    }
};