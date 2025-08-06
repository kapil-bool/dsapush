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
    
    bool isvalid(int r,int c,int n){
        return (r>=0 and r<n and c<n and c>=0);
    }

    int removeStones(vector<vector<int>>& stones) {
        //lets see same row and column
        //connect the componets //
        //only the ultimate parent is  will left 
        //row and col 
        //0 <= xi, yi <= 104 we are unaware of the 
        int maxRow = 0;
        int maxCol = 0;
        int n=stones.size();
        for (auto it : stones) {
           maxRow = max(maxRow, it[0]);
           maxCol = max(maxCol, it[1]);
        }

        //call the function here 
        //connect them first
        //row=row col 

        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int, int> stoneNodes; //ultimate parent me store kar dunga 
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            //cinnect the one in same row and column
            ds.unionBySize(nodeRow, nodeCol); //perfect till here 
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1; //here the  nodes are stored now calulate the parent from it by travesing the map
        }
          int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                cnt++;
            }
        }
        //cnt is the ultimate parent so at end remove the n- cnt that is the parent are left and all the other are REMOVED
        return n - cnt;
        
    }
};