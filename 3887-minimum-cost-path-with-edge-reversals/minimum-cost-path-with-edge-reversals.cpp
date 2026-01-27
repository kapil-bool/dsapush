class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        //the one with the minium cost will be the one i pick 
        int ans=0;
        vector<vector<pair<int,int>>> adj(n), radj(n);
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w}); //condtion matched here 
        }
        vector<int>visited(n,0);
        vector<int>distance(n,1e9);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0}); //0 ,0;
        distance[0]=0;
        //neighbours traversal
        while(!pq.empty()){
            auto [cost,node]=pq.top();
            pq.pop();

            if(cost>distance[node]) continue; //skip this part
            for(auto &[v,w]:adj[node]){
                //neighbour exploring 
                //u->v 
                if(distance[v]> cost+w){
                    distance[v]=cost+w;
                    //relaxed;
                    pq.push({distance[v],v});
                }
            }
            for(auto &[v,w]:radj[node]){
                //neighbour exploring 
                //u->v 
                long long cost_here=1LL*2 +w;
                if(distance[v]> cost_here+w){
                    distance[v]=cost_here+w;
                    //relaxed;
                    pq.push({distance[v],v});
                }
            }

        }
        return distance[n-1]==1e9 ? -1 :distance[n-1];
       
    }
};