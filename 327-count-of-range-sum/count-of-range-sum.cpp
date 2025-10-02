class Solution {
public:
    vector<int> tree;
    int n;

    // Update segment tree at index idx by val
    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(idx, val, 2*node+1, start, mid);
        else
            update(idx, val, 2*node+2, mid+1, end);

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    // Query sum in segment tree in range [l, r]
    int query(int l, int r, int node, int start, int end) {
        if (r < start || end < l) return 0;          // no overlap
        if (l <= start && end <= r) return tree[node]; // total overlap
        int mid = (start + end) / 2;
        return query(l, r, 2*node+1, start, mid) + query(l, r, 2*node+2, mid+1, end);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // lets do coordinate comprison upfront only 
        // no build query update 
        // now coordinate compression this is applied on unique value here anwer is not like in the array unique but the prefix one which are unique 
        vector<long long> prefix = {0}; // all 0 start assign
        set<long long> unique;          // use long long to avoid overflow
        for(auto &i : nums){
            prefix.push_back(prefix.back() + (long long)i); // cast to long long
        }

        // now unique one 
        for (auto p : prefix) {
            unique.insert(p);
            unique.insert(p - lower);
            unique.insert(p - upper);
        }

        // make index of this unique
        vector<long long> sorted(unique.begin(), unique.end());
        n = sorted.size();
        tree.assign(4*n, 0);

        auto getIndex = [&](long long x) {
            return (int)(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin());
        };

        int answer = 0;
        for(auto p : prefix){
            // traversing the main getting the index from the get index query and update
            // now here also check here for range
            int left = getIndex(p - upper);
            int right = getIndex(p - lower);
            if(left <= right) answer += query(left, right, 0, 0, n-1);
            update(getIndex(p), 1, 0, 0, n-1);
        }

        return answer;
    }
};
