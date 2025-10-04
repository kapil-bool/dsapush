class Solution {
public:
    vector<int> tree;
    int n;

    //template he copy kar le
    //query //update
    void update(int index, int start, int end, int pos, int val) {
        if (start == end) {
            tree[index] += val;
            return;
        }
        int mid = (start + end) / 2;

       
        if (pos <= mid) update(2 * index + 1, start, mid, pos, val);
        else update(2 * index + 2, mid + 1, end, pos, val);

       
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    int query(int index, int start, int end, int l, int r) {
        if (r < start || l > end) return 0;
        if (l <= start && end <= r) return tree[index];
        int mid = (start + end) / 2;

       
        return query(2 * index + 1, start, mid, l, r)
             + query(2 * index + 2, mid + 1, end, l, r);
    }

    int reversePairs(vector<int>& nums) {  
        int len = nums.size();
        if (len == 0) return 0;          

        //cordination compression 
        vector<long long> sorted;
        for (auto x : nums) {
            //2 bar karna ek time 2* bhi 
            sorted.emplace_back(x);
            sorted.emplace_back(2LL * x); //type compression ki kar de 
        }

        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        auto getIndex = [&](long long x) {
            return (int)(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin());
        };

        n = sorted.size();
        tree.assign(4 * n, 0);

        long long ans = 0;

        //last se traverse karna here 
        for (int i = len - 1; i >= 0; i--) {
            int pos = (int)(lower_bound(sorted.begin(), sorted.end(), (long long)nums[i]) - sorted.begin());
            ans += query(0, 0, n - 1, 0, pos - 1);

            // update tree with 2*nums[i]
            update(0, 0, n - 1, getIndex(2LL * nums[i]), 1);
        }

        return (int)ans;
    }
};
