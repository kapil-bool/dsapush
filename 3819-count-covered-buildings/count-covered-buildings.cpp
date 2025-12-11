class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
       //flow controll and 
       int ans=0;
      vector<int> pos_x(n+1, -1e9);
       vector<int> neg_x(n+1,  1e9);
      vector<int> pos_y(n+1, -1e9);
        vector<int> neg_y(n+1,  1e9);

       for(auto &i: buildings){
          int x=i[0];
          int y=i[1];
          //now what i have to do is make 4 searches here for this 4 loops naa man 
          //it should do the work like a map 
          pos_x[x]=max(pos_x[x],y);
          neg_x[x]=min(neg_x[x],y);
          pos_y[y]=max(pos_y[y],x);
          neg_y[y]=min(neg_y[y],x);
          //here i am creating boundries 
       }
     for(auto &i:buildings){
        int x=i[0];
        int y=i[1];
        //now for a given gegment if ther exit a lower value for same x and  a heiger value than x axis is sorted similay 
        //for the y axis also
        //x will be checked for y and vice
        if(y>neg_x[x] and y<pos_x[x]  and x<pos_y[y] and x>neg_y[y]) ans++;
     }
       
       return ans;
    }
};