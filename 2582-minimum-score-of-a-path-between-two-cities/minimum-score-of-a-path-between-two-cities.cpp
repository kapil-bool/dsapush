class Solution {
public:
    vector<int> parent, size;
    int findparent(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findparent(parent[x]);
    }

    void unite(int u, int v) {
        int upu = findparent(u);
        int upv = findparent(v);
        if (upu == upv) return;
        if (size[upu] < size[upv])
            swap(upu, upv);

        parent[upv] = upu;
        size[upu] += size[upv];
    }

    int minScore(int n, vector<vector<int>>& roads) {

        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : roads)
            unite(e[0], e[1]);

        int root = findparent(1);
        int ans = 1e9;
        for (auto &e : roads) {
            if (findparent(e[0]) == root)
                ans = min(ans, e[2]);
        }

        return ans;
    }
};