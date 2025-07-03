class Solution {
public:
    int helper(int index,vector<vector<int>>& books, int shelfWidth,vector<int> &dp){
        if(index==books.size())return 0;
        if(dp[index]!=-1)return dp[index];
        
        int ans_height=1e9;
        int height=0,width=0;
        for(int i=index;i<books.size();i++){
            //now u incoparte in existing one or create new one and also keeo the track of max of height of each self
            width+=books[i][0];
            if(width>shelfWidth) break;
            height=max(height,books[i][1]);
            //now the remaing one  onces u decide to make make a new one no going back
            int next=helper(i+1,books,shelfWidth,dp); 
            ans_height=min(ans_height,height+next);
        }
        return dp[index]=ans_height;
        

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        //more like incoprate in an existing one or create a new one  minimum should be there so
        int n=books.size();
        vector<int>dp(n,-1);
        return helper(0,books,shelfWidth,dp);
    }
};