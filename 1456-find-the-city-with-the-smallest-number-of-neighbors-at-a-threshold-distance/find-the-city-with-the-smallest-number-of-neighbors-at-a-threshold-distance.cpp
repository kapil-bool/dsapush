typedef long long ll;
typedef pair<int,int> pii;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<pair<int,int>>>adj(n);
         for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
         }
         int ans=-1;
         int mazi=1e9;
         for(int i=0;i<n;i++){
            //try alll posiblites here 
            vector<int>distance(n,1e9);
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            distance[i]=0;
            pq.push({0,i});
            while(!pq.empty()){
                auto[d,node]=pq.top();
                pq.pop();
                //cycle is here 
                if(distance[node]!=d)continue;
                for(auto& [v,w]:adj[node]){
                    if(distance[node]+w<distance[v]){
                        distance[v]=distance[node]+w;
                        pq.push({distance[v],v});
                    }
                }
            }
            int cnt=0;
            // int mazi=1e9;
            for(int search=0;search<n;search++){
                if(search!=i and distance[search]<=distanceThreshold){
                    cnt++;
                }
            }
            // min count and maxnumber
            if(cnt<=mazi){
                mazi=cnt;
                ans=i;
            }
         }
         return ans;

    }
};