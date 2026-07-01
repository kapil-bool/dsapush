class Solution {
public:
    bool check(int mid,vector<vector<int>>&distance,int n){
        if(distance[0][0]<mid) return 0;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({0,0});
        vis[0][0]=1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            if(x==n-1 and y==n-1) return 1;
            //else push on the bases of distance mid;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                 if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny] && distance[nx][ny] >= mid){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                 }
            }
        }
        return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>distance(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        //the idea is to get the disatance from all the theves
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++ ){
                if(grid[i][j]==1){

                    distance[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            // auto tp=q.front();
            // int sx=tp[0];
            // int sy=tp[1];
            auto [sx, sy] = q.front();
            q.pop();
            //boundary check and distance min 
            for(int k=0;k<4;k++){
                   int nwx=sx+dx[k];
                   int nwy=sy+dy[k];
                   if(nwx>=0 and nwy>=0 and nwx<n and nwy<n and distance[nwx][nwy]==-1){
                       distance[nwx][nwy]=distance[sx][sy]+1;
                       //ulametly the manhattern is 1 for adj right;
                       q.push({nwx,nwy});
                   }
            }
        }
        int low=0;
        int high=2*(n-1); // max manahetten that it;
        int ans=0;
        while(low<=high){
            int mid=(low)+(high-low)/2;
            if(check(mid,distance,n)){
                ans=mid;
                low=mid+1;
            }
            else{
              high=mid-1;
            }
        }
        return ans;
    }
};