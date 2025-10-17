class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        //map -with frequency 
        //map the modulo one here try to make a sequence if there is a 0 1 2 3 4 in modulo and a certain is missing 
        //that is the answer will do it 
        int n=nums.size();
        vector<int>map(value,0);
        for(int i=0;i<n;i++){
         int idx = ((nums[i] % value) + value) % value;
         map[idx]++;

           //will this also do for the negative dry run
        }
        //now traverse it till a condtion u find it zero again
        //max how many times a loop can be there always till the condtion
        int ptr_formap=0;
        while(true){
            //also need a pointer on it aand back to start so rotated array kind
            int ptr=(ptr_formap % value);
            if(map[ptr]==0) return  ptr_formap;

            // else

            map[ptr]--;
            ptr_formap++;

        }
        return ptr_formap;
        

    }
};