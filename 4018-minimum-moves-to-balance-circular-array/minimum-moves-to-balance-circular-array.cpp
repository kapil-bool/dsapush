class Solution {
public:
    long long minMoves(vector<int>& balance) {

        // sum check
        long long sum = accumulate(balance.begin(), balance.end(), 0LL);
        if(sum < 0) return -1;

        // no negative = return 0;
        bool negative = 0;
        int index = -1;

        for(int i = 0; i < balance.size(); i++){
            if(balance[i] < 0){
                negative = 1;
                // store the index also
                index = i;
                break;
            }
        }

        if(!negative) return 0;

        // function when negative is there
        // so here u got the index
        // like 2pointer from both ends and keep on doing it till they are at a same point
        // moves will be like index - position of that

        long long ans = 0;
        long long need = -balance[index];

        // recheck the right and left as they are circular
        int penalty = 1;

        while(need > 0 && penalty < balance.size()){
            // till zero here 8/1/26
            // not to be zero and closest will be the one reducing it
            // intersection condition ke need hai he nahi i guess
            // bcz it will get 0 or the neg sum will be the answer

            int left  = (index - penalty + balance.size()) % balance.size();
            int right = (index + penalty) % balance.size();

            // pick one and
            if(balance[left] > 0){
                // u dont take all u take the one needed or are present that is min of both
                long long take = min(need, (long long)balance[left]);
                balance[left] -= take; // well this is something which is of no use
                need -= take;
                // in answer there must be a penalty also going on remember
                ans += take * penalty;
            }

            if(need > 0 && right != left && balance[right] > 0){
                long long take = min(need, (long long)balance[right]);
                balance[right] -= take; // well this is something which is of no use
                need -= take;
                // in answer there must be a penalty also going on remember
                ans += take * penalty;
            }

            penalty++; // ready for next
        }

        return (need == 0) ? ans : -1;
    }
};
