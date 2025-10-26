class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //idea  is clear but now how will i see if n is performed or not maye with the size of hash map
        //lets see;
         unordered_map<char, int> freq;
         for (auto &t : tasks) freq[t]++;

        priority_queue<int> pq; 
        for (auto &it : freq) pq.push(it.second);

        queue<pair<int,int>>q;
        int ans=0;
        while(!pq.empty() or !q.empty()){
            ans++;
            if(!pq.empty()) {
                int tp = pq.top(); 
                pq.pop();
                tp--;
                if(tp > 0) {
                    
                    q.push({tp, ans + n});
                }
            }
            while(!q.empty() and q.front().second==ans){
                //back to the pq;
                //ans also so that it can click 
                pq.push(q.front().first);
                //what if any few are left here and there time is not then empty still
                 q.pop();
            }
        }
       return ans;
    }
};