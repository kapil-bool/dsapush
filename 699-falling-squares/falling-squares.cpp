class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        /* so lazy propogation is here but brute force first 
           overlap karte hai  add them insted of minusing the whrn it end it will be usless just increase the range and if overlap increase the height 
           //problem is one that wont overlap in the instant it map be nevwe calulated andall furter are that then also a problem  
           //sort cant possible as it will change the out put
        */
        
        vector<int> ans;
        vector<pair<pair<int,int>,int>> intervals;
        int globalMax = 0;

        for (auto &i : positions) {
            int left = i[0];
            int height_of_curr = i[1];
            int right = left + height_of_curr;
            int height = 0;

            // check with all the previous ones stored in the intervals;
            for (auto &[range, h] : intervals) {
                int lt = range.first;
                int r2 = range.second;
                // overlap condition 
                if (right > lt && left < r2) {
                    height = max(height, h);
                }
            }

            // now this height needs to be added 
            int new_height = height_of_curr + height;

            // push into the intervals 
            intervals.push_back({{left, right}, new_height});
            
            globalMax = max(globalMax, new_height);
            ans.push_back(globalMax);
        }

        return ans;
    }
};
