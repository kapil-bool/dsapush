class Solution {
public:
 class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        //core logic is attach it to the smaller one 
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //map use kar if set.find() !=end then just just return the make the parent one true
        // first one is the name so iterate from second i.e the 1st index
        //its a 2d array
        int n=accounts.size();
        DisjointSet ds(n);
        sort(accounts.begin(),accounts.end());
        unordered_map<string,int>mp;
      for(int i = 0; i < n; i++) {
          for (int j = 1; j < accounts[i].size(); j++) {
                string &mail = accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    //this means its not there
                    //make it the child of i
                    mp[mail]=i;
                    //done
                }
                else{
                    //so here the i will be one  and the index to which it is mapped
                    ds.unionBySize(i,mp[mail]);
                    //so the connection are done till here now in next the ultimate parent 
                }
            }
        }
        //the ultimate parent 
        vector<string> mergedMail[n];
        for(auto i:mp){
            //<string,int> int will be the up
           string mail=i.first;
           int node=ds.findUPar(i.second); //so here the ultimate parent is stored and and once u find it store the string to it
           mergedMail[node].push_back(mail); //stored here
        }
        //sorted ordere me represent karni hai
        vector<vector<string>>final;
        for(int i=0;i<n;i++){
         sort(mergedMail[i].begin(), mergedMail[i].end()); //needed in sorted ordere
            if( mergedMail[i].size()==0)continue;
            vector<string>temp;
            //here take the name from accountsin temp
            temp.push_back(accounts[i][0]);
            for(auto j:mergedMail[i]){
                temp.push_back(j);
            }
            final.push_back(temp);
        }

         return final;
    }
};