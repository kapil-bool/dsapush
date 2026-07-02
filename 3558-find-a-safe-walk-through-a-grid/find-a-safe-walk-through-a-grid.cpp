class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        queue<tuple<int,int,int>>q;
        vector<vector<int>> best(m, vector<int>(n, -1));
        if((health-grid[0][0])<=0) return false;
        //i, j, heath all i have to do is reach the end ;
        q.push({0,0,health-grid[0][0]});
        while(!q.empty()){
            auto [x,y,curhealth]=q.front();
            q.pop();
            if(x==m-1 and y==n-1) return 1;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                //in boundary and helth if u minus should not be neg
               if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue; //copied logic dont want to code that long sht;
                int nh=curhealth-grid[nx][ny];
                if(nh<=0){
                    //u done 
                    continue;
                }
                if(nh>best[nx][ny]){
                    q.push({nx,ny,nh});
                    best[nx][ny]=nh;
                }
                
            }
        }
        return 0;
    }
};