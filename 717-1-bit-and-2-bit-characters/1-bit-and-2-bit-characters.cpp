class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //always a 0 at end look if it is unconsumed i.e contrting to the firdt character
      int i = 0;
        while (i < bits.size() - 1) {
            if(bits[i]==1)i+=2;
            else{
                i++;
            }
        }
        return i == bits.size() - 1;
    }
};