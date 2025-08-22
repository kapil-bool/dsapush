class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        //length is needeed so min row and min col and simmlary max row and max col 
        int n=grid.size();
        int m=grid[0].size();
        int min_r=n;
        int min_c=m;
        int max_r=0;
        int max_c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //0 indexed also so keep in mind 
                if(grid[i][j]==1){
                    min_r = min(min_r, i);
                    min_c = min(min_c, j);
                    max_r = max(max_r, i);
                    max_c = max(max_c, j);
                }
            }
        }
          return (max_r - min_r + 1) * (max_c - min_c + 1);
    }
};