class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxheight_r=0;
        int maxheight_l=0;
        int right=n-1,left=0;
        int water=0;
        while(left<=right){
            //should be eqaual
            if(height[right]>height[left]){
                //u got an container 
                maxheight_l=max(maxheight_l,height[left]);
                water+=maxheight_l-height[left];
                left++;
            }
            else{
                 maxheight_r=max(maxheight_r,height[right]);
                water+=maxheight_r-height[right];
                right--;
            }
        }
   return water;
    }
};