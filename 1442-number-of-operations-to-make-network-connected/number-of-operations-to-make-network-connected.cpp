class Solution {
public:
    class dis{
     private:
     public:
     vector<int> rank,parent;
     dis(int n){
        //parent all themself rank initally one
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
     }
     int findparent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findparent(parent[node]);
     }
     //3 cases here
     bool unionbyrank(int u ,int v){
        int up_u=findparent(u);
        int up_v=findparent(v);
        if(up_u==up_v) return false ;
        if(rank[up_u]>rank[up_v]){
            parent[up_v]=up_u;
        }
         else if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
        }
        else{
            //equal case here 
            parent[up_v]=up_u;
            rank[up_u]++; //if i used the size one it should be twice
        }
        return true;
     }
     
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        //n-1 for n connection
        //count no of connection as well as the connected  omponets
        //dsu 
         if (connections.size() < n - 1) return -1;
        dis dsu(n);
        int extraedges=0;
      
        //if the ultimate parent is same u increase the extra edges count
       for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            // If union returns false, edge is extra
            if (!dsu.unionbyrank(u, v)) {
                extraedges++;
            }
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findparent(i) == i) {
                components++;
            }
        }
                //so if the parent is itself connected componets++
       
        //count -- as for one will be the ultimate parent here 
       int needed = components - 1;

        if (extraedges >= needed)
            return needed;
        else
            return -1;
    }
};