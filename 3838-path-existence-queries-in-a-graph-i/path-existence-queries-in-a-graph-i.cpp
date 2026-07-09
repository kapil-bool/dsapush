class Solution {
public:
    vector<int>parent,sz;
    int findparent(int x){
        if(x==parent[x]){
            return x;
        }
        //else recursivly find the ultimate parent ;
        return parent[x]=findparent(parent[x]);
    }
    void unite(int x,int v){
        x=findparent(x);
        v=findparent(v);
        if(x==v){
            return ;
            //same ultimate parent
        }
        if(sz[x]<sz[v]){
            swap(x,v);
        }

        parent[v]=x;
        if(sz[x]==sz[v]){
            sz[x]++;
        }

    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<vector<int>>adj;
        parent.resize(n);
        sz.assign(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        //now just look for edge if there is any //either proced queries 
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                unite(i,i-1);
            }
        }

        for(auto &i:queries){
            int u=i[0];
            int v=i[1];
            if(parent[u]==parent[v]){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }

        return ans;
    }
};