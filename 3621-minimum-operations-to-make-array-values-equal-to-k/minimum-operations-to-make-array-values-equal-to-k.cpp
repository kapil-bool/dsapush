class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //it is valid only if all the number are are greater and aree greater theanit
        //make unordereed set here;
        unordered_set<int>mp;
        // int ans=0;
        for(auto & i :nums){
            if(i<k)return -1;
            else if( i>k)
            mp.insert(i);
            //this will handel the smaller no case
        }
        //now procede with the operation

       return mp.size(); //as only different elemnt will be passed down
    }
};