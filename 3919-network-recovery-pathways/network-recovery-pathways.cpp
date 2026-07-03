typedef long long ll;
#define ld 1e18
class Solution {
public:
    bool dij(int mid,ll k,vector<vector<pair<int,int>>>&adj,int n){
        vector<ll>distance(n,ld);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        distance[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if (d != distance[u]) continue;
            for(auto &[v,w]:adj[u]){
                if(w<mid) continue;
                if(distance[u]+w<distance[v]){
                    //so this is edge relaxation right update the weight'
                    distance[v]=distance[u]+w;
                    pq.push({distance[v],v});
                }
            }
        }

          return distance[n-1]<=k;
        
    };
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        //dijakstra 
        //no cycle also so will do righht
        //before selection see for the online one and lets procedee 
        //check for posssiblity of smller and a path should be there 
        int n=online.size();
        int upperbound=0;
        vector<vector<pair<int,int>>>adj(n);
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            //if u or v is absent then the path cant be taken right
            if(u!=0 and u!=n-1 and !online[u])continue;
            if(v!=0 and v!=n-1 and !online[v])continue;
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
            upperbound=max(upperbound,w);
        }
        int start=0;
        int end=upperbound;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)>>1;
            if(dij(mid,k,adj,n)){
                //this mean a path is there having this as the min now  more samll;
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};