class Solution {
public:
    const int MOD=1e9+7;
    // return dfs(1, n, adj, dist, dp);
    //kind of pick or not pick only
   int helper(int index, int n, vector<vector<pair<int, int>>> &adj,
               vector<int>& dist, vector<int>& dp) {
        if (index == n) return 1;
        if (dp[index] != -1) return dp[index];

        int ways = 0;
        for (auto& neigh : adj[index]) {
            int v = neigh.first;
            if (dist[index] > dist[v]) {
                ways = (ways + helper(v, n, adj, dist, dp)) % MOD;
            }
        }
        return dp[index] = ways;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        //distance so dj 
        //undirected from n=1 to n=end
        //dp multiple options 
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[n] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, n});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            for (auto& [v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> dp(n + 1, -1);
        return helper(1, n, adj, dist, dp);
    }
};