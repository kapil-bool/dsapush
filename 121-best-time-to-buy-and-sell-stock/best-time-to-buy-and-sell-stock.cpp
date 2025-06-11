class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //not a dp problem if u ask me just basic simulation 
        int minPrice = INT_MAX;  
        int maxProfit = 0;       

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;  
            } else {
                maxProfit = max(maxProfit, price - minPrice); 
            }
        }

        return maxProfit;
    }
};