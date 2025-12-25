// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
//         sort(happiness.begin(),happiness.end());
//         int ans=0;
//         int i=happiness.size();
//         int counter=0;
//         while(k--){
//             if(happiness[i]<0) break;
//            if(happiness[i]>=0){
//             ans+=happiness[i]-counter;
//            }
//            counter++;
//            i--;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long ans = 0;
        int counter = 0;
        int i = happiness.size() - 1;

        while (k-- && i >= 0) {
            if (happiness[i] - counter <= 0) break;
            ans += happiness[i] - counter;
            counter++;
            i--;
        }
        return ans;
    }
};
