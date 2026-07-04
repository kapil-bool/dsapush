class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        //intersection and then removal;
        vector<vector<int>>merged;
        vector<vector<int>>ans;
        int n=occupiedIntervals.size();
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        int l=occupiedIntervals[0][0];
        int r=occupiedIntervals[0][1];
        for(int i=1;i<n;i++){
             int al=occupiedIntervals[i][0];
             int ar=occupiedIntervals[i][1];
             //check with the prev one and see 
             //they overlap and they do not 2 cases are here
            //  case1
            if(al>r+1){
                merged.push_back({l,r});
                l=al;
                r=ar;
            }
            else{
                l=min(l,al);
                r=max(r,ar);
            }
        }
        merged.push_back({l,r});

        for(auto &i:merged){
            int l=i[0];
            int r=i[1];
            //see if there is an overlap and accordingly manage the 
            if(r<freeStart ||l>freeEnd){
                ans.push_back({l,r});
            }
            else{
                // for left path
                if(l<freeStart){
                    ans.push_back({l,freeStart-1});
                }
                if(freeEnd<r){
                    ans.push_back({freeEnd+1,r});
                }
            }


        }
        return ans;

    }
};