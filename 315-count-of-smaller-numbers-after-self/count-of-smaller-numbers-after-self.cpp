class Solution {
public:
    vector<int> tree;
    int n;

    //no need for the build daddy
    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node + 1, start, mid);   
        else
            update(idx, val, 2 * node + 2, mid + 1, end);   

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    
    int query(int l, int r, int node, int start, int end) {
        if (r < start || end < l) return 0;      // no overlap
        if (l <= start && end <= r) return tree[node];  // total overlap
        int mid = (start + end) / 2;
        return query(l, r, 2 * node + 1, start, mid) +
               query(l, r, 2 * node + 2, mid + 1, end);
    }

    vector<int> countSmaller(vector<int>& nums) {
        // Coordinate compression
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        auto getIndex = [&](int x) {
            return (int)(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin());  
        };

        n = sorted.size();
        tree.assign(4 * n, 0);  //mathematically 4*n is sufficent so take that only 

        int sz = nums.size();
        vector<int> res(sz, 0);
        //now here is the main thing from back and also see 
        for (int i = sz - 1; i >= 0; i--) {
            int idx = getIndex(nums[i]);
            if (idx > 0) 
                res[i] = query(0, idx - 1, 0, 0, n - 1); 
                //serch in  0 to index -1 
            update(idx, 1, 0, 0, n - 1);
            //update this one at end so it can be added 
        }

        return res;
    }
};
