class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int ans = -1;
        int kepper = -1;
        vector<int> osh;

        int xc = center[0];
        int yc = center[1];

        for (int i = 0; i < towers.size(); i++) {
            int tx = towers[i][0];
            int ty = towers[i][1];
            int q_factor = towers[i][2];

            int distance = abs(xc - tx) + abs(yc - ty);

            if (distance <= radius) {
                if (q_factor > ans) {
                    ans = q_factor;
                    kepper = i;
                } else if (q_factor == ans) {
                    if (kepper == -1 ||
                        tx < towers[kepper][0] ||
                        (tx == towers[kepper][0] && ty < towers[kepper][1])) {
                        kepper = i;
                    }
                }
            }
        }

        if (kepper == -1) return {-1, -1};

        osh.push_back(towers[kepper][0]);
        osh.push_back(towers[kepper][1]);

        return osh;
    }
};
