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

    int ans=0;

    int largestIsland(vector<vector<int>>& grid) {
        //connect the componets 
        //make all zeros 1 and see all the possiblties here 
        //lets connect them first i need nodes
        int n=grid.size();
        DisjointSet dis(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //if 1 start the connection else leave
                if(grid[i][j]==0) continue;
                int d_x[]={1,-1,0,0};
                int d_c[]={0,0,-1,1};
                for(int ii=0;ii<4;ii++){
                    int new_x=i+d_x[ii];
                    int new_c=j+d_c[ii];
                    //validty 
                    if(isvalid(new_x,new_c,n) and grid[new_x][new_c]==1){
                        //union it one node will be the origanl one and the next will be the new one
                        int oldnode=i*n+j;
                        int newnode=new_x*n+new_c;
                        dis.unionBySize(oldnode,newnode);
                        //ok the connection are done 
                    }
                }
            }
        }

        //now transfform the zero onto 1 and see for a grp formation
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //if 1 start the connection else leave
                if(grid[i][j]==1) continue;
                set<int>comp;
                int d_x[]={1,-1,0,0};
                int d_c[]={0,0,-1,1};
                for(int ii=0;ii<4;ii++){
                    int new_x=i+d_x[ii];
                    int new_c=j+d_c[ii];
                    //validty 
                    if(isvalid(new_x,new_c,n) and grid[new_x][new_c]==1){
                        //u parent of the current new node 
                        int newnode=new_x*n+new_c;
                        comp.insert(dis.findUPar(newnode));
                        //ok next is to see the size by oterating over it
                    }
                }
                int sizee = 0;
                for (auto parentId : comp) {
                    sizee += dis.size[parentId];  
                }
                sizee += 1; // adding the converted 0
                ans = max(ans, sizee); // fix: update ans here
            }
        }

        //like there is a case where u can connect but still u have a bigger island in existance basically all 1;
        for(int i=0;i<n*n;i++){
            ans=max(ans,dis.size[(dis.findUPar(i))]);
        }

        //size here is the array also so u return the size of ultimate parent 
        return ans;
    }
};
