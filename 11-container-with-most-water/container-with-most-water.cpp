class Solution {
public:
    int maxArea(vector<int>& height) {
        //submit as the dailey only 
        //max water is needed->height and width is the one width both diffference and width
        //height wale ko kese kar sakta hu like jo min hoga use he age bada deta in hope of better
        int n=height.size();
        int left_most=0;
        int right_most=n-1;
        int ans=0;
        while(right_most>left_most){
          int width=abs(left_most-right_most);
          int h=0;
          if(height[right_most]>height[left_most]){
             h=height[left_most];
             left_most++;
          }
          else{
             h=height[right_most];
             right_most--;  //next iterations

          }

          ans=max(ans,h*width);
          
        }
        return ans;
    }
};