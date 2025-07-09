class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        //so bascially continous time lana hai non overlapping 
        /* till now what i have underestood is it is asking the total no of free time here and store 
        them in a varible and return it 
        atmost k can be performed */
        /* so here the approch is like take the free time and since k are allowed this mean k+1 are together the window 
         size to be k+1 and return the maximum possible answer*/
        // int maxfree=-1e9;
        int n=endTime.size();
        vector<long long>free_time;
        free_time.push_back(startTime[0]-0); //first one is this
        for(int i=1;i<startTime.size();i++){
        free_time.push_back(startTime[i]-endTime[i-1]); 
        }
        //now add the edge case 
        free_time.push_back(eventTime-endTime.back()); 
          int windowSize = k + 1;
        int maxfree = 0;
        long long sum = 0;
        int left = 0;

        for (int right = 0; right < free_time.size(); right++) {
          sum += free_time[right];

            if (right - left + 1 > windowSize) {
                sum -= free_time[left];
                left++;
            }

            if (right - left + 1 == windowSize) {
                maxfree = max(maxfree, (int)sum);
            }
        }


        return maxfree;

    }
};