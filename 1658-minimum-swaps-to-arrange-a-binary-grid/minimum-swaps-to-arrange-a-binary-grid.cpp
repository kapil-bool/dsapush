class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        //first check if it exist or not and then simulate
        //from 0 from n=n-1 to 1 atlest that to at back and we have them as the answer 
        int n=grid.size();
        int m=grid[0].size();
        vector<int>count(n);
        for(int i=0;i<n;i++){
            // bool flag=1; //1 hai ki nahi; 
                int length=0;
            for(int j=m-1;j>=0;j--){
                 if(grid[i][j]==0){
                    length++;
                 }
                 else
                   break; 
                 
            }

            count[i]=length;
        }
          int ans = 0;

        for(int i = 0; i < n; i++) {
            int need = n - 1 - i;
            int j = i;
            while(j < n && count[j] < need)
                j++;

            if(j == n)
                return -1;
            while(j > i) {
                swap(count[j], count[j-1]);
                ans++;
                j--;
            }
        }

       return ans;

    }
};