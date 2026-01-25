class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> positive;
        vector<int>index;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                positive.push_back(nums[i]);
                index.push_back(i);
                // nums[i] = 0;   this cretes a problem then 
            }
        }
        

        int n = nums.size();
        int s = positive.size();
        if (s == 0) return nums;
        k=k%s;
        rotate(positive.begin(), positive.begin() + k, positive.end());
        //now done ;
        for(int i=0;i<s;i++){
            nums[index[i]]=positive[i];
        }


        // reverse(positive.begin(), positive.end());

        // int st = k % s;   
        // int i = 0;

        // while (i < n) {
        //     if (nums[i] == 0) {
        //         nums[i] = positive[st];
        //         st = (st + 1) % s;  
        //     }
        //     i++;
        // }

        return nums;
    }
};
