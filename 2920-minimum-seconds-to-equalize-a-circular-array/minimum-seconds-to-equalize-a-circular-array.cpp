class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        //all the distict one 
         int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        //now the mathematical part; h,
        int answer=1e9; //1e5+1

         for(auto &[val,index]:pos){
            int mgap=0;
            for(int i=0;i<index.size();i++){
                int next=index[(i+1)%index.size()];
                int gap=(next-index[i]-1+n)%n;
                //minus from current to next
                mgap=max(gap,mgap);
            }
             answer = min(answer, (mgap + 1) / 2);
         }
         return answer;
    }
};