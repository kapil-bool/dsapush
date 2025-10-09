class Solution {
public:
    bool canJump(vector<int>& nums) {
        //ok last or not i can reach
        //max here could me 1  to the given one right 
        //okay so if can reach that whould be great
        //index 1 to n
        //u have to reach last some how 
        //INTUTION n-1 ->with i+nums[i];
        int n=nums.size();
        int last =n-1;
        int maxreach=0; //till where u can go from a particular point if it is zero some how u cant reach at all 
        for(int i=0;i<n;i++){
            if(i>maxreach) return false; //iam at a index where icant reach so that is why it is false 
            //for this a global max hwere u can rech is needed; ig this will do the trick
            maxreach=max(maxreach,i+nums[i]);
            if(maxreach>=last){
                return true;
            }
        }

        return 1;
        //one edge case is that u are on 0 always no matter the condtion 
        
    }
};