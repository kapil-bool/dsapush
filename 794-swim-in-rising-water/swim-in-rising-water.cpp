class Solution {
public:
    int x_new[4]={1,-1,0,0};
    int y_new[4]={0,0,-1,1};
    
    bool isvalid(int row,int col,int n){
         return(row>=0 and row<n and col>=0 and col<n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        //at last watever is ther that time will be needed no watter what u do
        //continous swimming also there
        //i think a normal bfs will work here optimzation i can look afterwards
        //well on a block all 4 direction just adding the minium will work?,
        int n=grid.size();
        // int m=grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        ///value hogi and index
        //just push the first one here
        //visted bhi bana le u may just be in a loop if u take it 
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        pq.push({grid[0][0],0,0});
        visited[0][0]=1;

        int ans=0;
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            int height=tp[0];
            int x=tp[1];
            int y=tp[2];
            //all four direction 
            //and all the exit condtion just check here only 
            ans=max(ans,height);
            if(x==(n-1) and y==(n-1)){
                return ans;
            }
            for(int i=0;i<4;i++){
                int newx=x+x_new[i];
                int newy=y+y_new[i];
                //valid hai 
                if(isvalid(newx,newy,n) and !visited[newx][newy]){
                    //mark it visited and after that
                    visited[newx][newy]=1;
                    pq.push({grid[newx][newy],newx,newy});
                    
                }
            }
        }
        return ans;
    }
};