class Solution {
public:
  class DisjointSet {
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            size.resize(n,1);
            for(int i=0; i<n; i++) {
                parent[i] = i;
            }
        }
        int findUPar(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionBySize(int u, int v) {
            int upu = findUPar(u);
            int upv = findUPar(v);
            if(upu == upv) return;
            if(size[upu] < size[upv]) {
                parent[upu] = upv;
                size[upv] += size[upu];
            } else {
                parent[upv] = upu;
                size[upu] += size[upv];
            }
        }
    };
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //so bascially return the one edge  that make a cycle;
        //traverse the edges array make connecttion 
        //so if the ultimate parent is same after the connection also i return that wedge only
        int n=edges.size();
        DisjointSet dis(n+1);
        int ans=-1e9;
        for(auto i:edges){
            int node_1=i[0];
            int node_2=i[1];
            if(dis.findUPar(node_1) !=dis.findUPar(node_2)){
            dis.unionBySize(node_1,node_2);
            }
            else
            return i;
//if the ultimate parent is same then that edge will create the cycle and u return it

        }
        return {};
    }
};