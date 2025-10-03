class Solution {
public:
    bool isvalid(int row,int col,int n ,int m){
        return (row<n and row>=0 and col<m and col>=0);
    }
    int new_x[4]={1,-1,0,0};
    int new_y[4]={0,0,-1,1};
    //i tjink these are the two one 
    int trapRainWater(vector<vector<int>>& heightMap) {
        // thinging of multisource bfs here 
        //see always go for the samller one and if any samller is obtained from it it will contribute to the water addition 
        //from all the neighous 
        //water inc on the basic like if a depreesion is there  alower height is obtained 
        //so mostly  of figured it out
         int n=heightMap.size();
         int m=heightMap[0].size();
         //height and index ->2 hai x and y so pair it 
         priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
         //like height and the indexis
         vector<vector<bool>>visited(n,vector<bool>(m,0));
         //push the boundries 
         //here also two time as 
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0 or j==m-1){
                    pq.push({heightMap[i][j],{i,j}});
                    visited[i][j]=1;
                }
            }
         }
        for(int j=0;j<m;j++){   
            if(!visited[0][j]){
                pq.push({heightMap[0][j],{0,j}});
                visited[0][j]=1;
            }
            if(!visited[n-1][j]){
                pq.push({heightMap[n-1][j],{n-1,j}});
                visited[n-1][j]=1;
            }
        }

         int ans=0;
         while(!pq.empty()){
            //as usulal top elem direction traversal and validating the condtion for increment 
            //also a visited neede 
            auto [h,index]=pq.top();
            pq.pop();
            int x=index.first;
            int y=index.second;
            //valid it and next 4 direction
           for(int i=0;i<4;i++){
             int n_x=x+new_x[i];
             int n_y=y+new_y[i]; 
             if(!isvalid(n_x,n_y,n,m) or visited[n_x][n_y]) continue;
             //else mark it visited  and do the calci for height here
             visited[n_x][n_y]=1;
             //height ??
             if(heightMap[n_x][n_y]<h){
                ans+=(h-heightMap[n_x][n_y]);
             }
            //    now push this one also
               pq.push({max(heightMap[n_x][n_y], h), {n_x, n_y}});
           }
         }
       return ans;
    }
};