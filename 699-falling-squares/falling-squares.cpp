class SegmentTree {
public:
    vector<int> tree, lazy;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    // Push the lazy value down to children (0-based)
    void pushDown(int idx, int l, int r) {
        if (lazy[idx] == 0 || l == r) return; // nothing to propagate or leaf

        int mid = (l + r) / 2;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        // propagate the lazy value to children
        tree[left] = max(tree[left], lazy[idx]);
        tree[right] = max(tree[right], lazy[idx]);
        lazy[left] = max(lazy[left], lazy[idx]);
        lazy[right] = max(lazy[right], lazy[idx]);

        lazy[idx] = 0; // clear after pushing
    }

    // Range update: set [ql, qr] to max(current, val)
    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr < l || ql > r) return; // no overlap
        if (ql <= l && r <= qr) { // total overlap
            tree[idx] = max(tree[idx], val);
            lazy[idx] = max(lazy[idx], val);
            return;
        }

        pushDown(idx, l, r);
        int mid = (l + r) / 2;
        update(2 * idx + 1, l, mid, ql, qr, val);
        update(2 * idx + 2, mid + 1, r, ql, qr, val);

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    // Range query: max in [ql, qr]
    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0; // no overlap
        if (ql <= l && r <= qr) return tree[idx]; // total overlap

        pushDown(idx, l, r);
        int mid = (l + r) / 2;
        return max(query(2 * idx + 1, l, mid, ql, qr),
                   query(2 * idx + 2, mid + 1, r, ql, qr));
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        
        vector<int> coords;
        for (auto &p : positions) {
            coords.push_back(p[0]);
            coords.push_back(p[0] + p[1]);
        }

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        auto getIndex = [&](int x) {
            return (int)(lower_bound(coords.begin(), coords.end(), x) - coords.begin());
        };

       
        SegmentTree seg(coords.size());
        vector<int> ans;
        int globalMax = 0;

        
        for (auto &p : positions) {
            int L = getIndex(p[0]);
            int R = getIndex(p[0] + p[1]) - 1; 
            int base = seg.query(0, 0, seg.n - 1, L, R);
            int newHeight = base + p[1];
            seg.update(0, 0, seg.n - 1, L, R, newHeight);
            globalMax = max(globalMax, newHeight);
            ans.push_back(globalMax);
        }

        return ans;
    }
};
