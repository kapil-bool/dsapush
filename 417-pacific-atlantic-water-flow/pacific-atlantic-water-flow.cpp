class Solution {
public:
    int newx[4]={1,-1,0,0};
    int newy[4]={0,0,1,-1};
    bool isvalid(int row,int col,int n,int m){
        return (row>=0 and row<n and col>=0 and col<m);
    }
    void travel(vector<vector<int>>& heights,queue<pair<int,int>>&q,vector<vector<bool>> &ocean,int n,int m){
        while(!q.empty()){
            //pick the top and traverse
            auto [x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int new_x=x+newx[i];
                int new_y=y+newy[i];
                //check for validty and caondtion push it markit =1 and procdede
                if(isvalid(new_x,new_y,n,m) and !ocean[new_x][new_y] and heights[x][y]<=heights[new_x][new_y]){
                     ocean[new_x][new_y]=1;
                     q.push({new_x,new_y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //okay will do it 
        //larger on e will act as the wall which will stop from entring atlantic to pacific and vice versa
        //border one always flow 
        //can i do like 
        //well innsted of above do the reverse terminolgy here 
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,0));
        vector<vector<bool>>atlantic(n,vector<bool>(m,0));
        //queue banan
        // pacif differ atlantic differ
        queue<pair<int,int>>at,pac;
        //
        //pac fil be i of each and j=0 and j each i =1 intersction should not do a problem as in bool=1 wont matter
        //now the  left side one 
        for(int j=0;j<m;j++){
            pac.push({0,j});
            pacific[0][j]=1;
        }
        for(int j=0;j<n;j++){
            pac.push({j,0});
            pacific[j][0]=1;
        }

        //now push into the at que
        for(int i=0;i<n;i++){
            at.push({i,m-1});
            atlantic[i][m-1]=1;
        }
        for(int j=0;j<m;j++){
            at.push({n-1,j});
            atlantic[n-1][j]=1;
        }
        //creation done now ehat traverse all 4 from que writing 2 times beeter i make a function and call;
        travel(heights,at,atlantic,n,m);
        travel(heights,pac,pacific,n,m);

        //now look for common and push them into the answer 
        vector<vector<int>>ans;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
         }

        
        return ans;
    }
};