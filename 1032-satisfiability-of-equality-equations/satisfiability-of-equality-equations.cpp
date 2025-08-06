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
    
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
          DisjointSet dis(26); // 26 letters

       
        for (auto &eq : equations) {
            if (eq[1] == '=')
                dis.unionBySize(eq[0] - 'a', eq[3] - 'a');
        }

        //ultimate parent is same and ! is there u return false
        for (auto &eq : equations) {
            if (eq[1] == '!')
                if (dis.findUPar(eq[0] - 'a') == dis.findUPar(eq[3] - 'a'))
                    return false;
        }

        return true;
    }
};