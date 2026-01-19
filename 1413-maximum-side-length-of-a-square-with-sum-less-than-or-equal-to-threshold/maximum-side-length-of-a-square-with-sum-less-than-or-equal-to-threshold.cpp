class Solution {
public:
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
       //square 1 ,2 ,3 like this only 
       //less then threhold and have is a square prefix will work
       // any one direction prefix will work 
       int n=mat.size();
       int m=mat[0].size();
       vector<vector<int>>prefix(n+1,vector<int>(m+1,0));
       for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
            //prefix here implent like before i ans j i poition that is 
            //- prefix as it is contributing doubles 
             prefix[i][j]=mat[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
             //up down and all
          }
       }
       //this one is only eft
       //this means t
       auto getsum=[&](int x,int y,int k){
         // k is the limit here and x and y are column;
         return prefix[x+k][y+k]-prefix[x][y+k]-prefix[x+k][y]+prefix[x][y]; 
       };

        auto check = [&](int k) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {
                    if (getsum(i, j, k) <= threshold)
                        return true;
                }
            }
            return false;
        };

        int low=1,high=min(n,m);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid)){
                ans=mid;
                //this means it is a vzlid one try bigger and other smller
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
       return ans;
    }
};