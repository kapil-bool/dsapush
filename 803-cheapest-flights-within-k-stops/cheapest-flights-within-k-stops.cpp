class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
         for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adj[u].push_back({v, cost}); 
        }

        vector<int> distance(n, 1e9);
        distance[src] = 0;

        queue<pair<int, pair<int, int>>> q; 
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto [stops, p] = q.front(); q.pop();
            int node = p.first, cost = p.second;

            if (stops > k) continue; //concludede already
            //check for the other possiblites
            for (auto& [next, wt] : adj[node]) {
                if (cost + wt < distance[next]) {
                    distance[next] = cost + wt;
                    q.push({stops + 1, {next, cost + wt}});
                }
            }
        }

        return distance[dst] == 1e9 ? -1 : distance[dst];
    }
};
