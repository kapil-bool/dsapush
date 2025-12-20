class Solution {
public:
    int minOperations(vector<int>& nums) {
        //simulation se ho jayega ye to
        int dupc=0;
        unordered_map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
            if(mp[i]==2){
                dupc++;
            }
        }
        int n=nums.size();
        int current=0;
        int count=0;
        while(current!=n and dupc>0){
            //size condtion also if less then 3 u remove it completly
            //check the current elem and u remove always the top 3 
            count++; //dup hai
            
            if (n - current < 3) break;
            for(int i=0;i<3;i++){
              //check it it contribute to a dube 
              int v=nums[current+i];
              if(mp[v]==2){
                dupc--;
              }
                mp[v]--;

            }

            current += 3;
        }

        return count;
    }
};