class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0;
        int sum=0;
        while(i<costs.size() and costs[i]<=coins){
            coins-=costs[i];
            sum++;
            i++;
        }
        return sum;
    }
};