class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //crete the adj //source is not fixed use the priorty que
        vector<vector<pair<int,int>>>adj(n+1);
          for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        //time and node two parametre
         vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

       queue<pair<int, int>> pq;
        pq.push({0, k}); // {time, node}
        while(!pq.empty()){
            auto tpelem=pq.front();
            pq.pop();
            int time=tpelem.first;
            int node=tpelem.second;
            //if u vitnesh a lower one update it 
           for (auto neigh : adj[node]) {
                int next = neigh.first;
                int weight = neigh.second;

                if (dist[next] > time + weight) {
                    dist[next] = time + weight;
                    pq.push({dist[next], next});
                }
            }
        }
        //if any one is 1e9 return -1 else return themax of time
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1; 
        }

        return *max_element(dist.begin() + 1, dist.end());
    }
};