class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(auto i: s){
            freq[i]++;
        }
        //now do the count
        int count=0;
        bool hasodd=0; //mirror element ki taraha kam ayega
        for(auto [ch,cnt]: freq){
            if(cnt%2==0){
                count+=cnt;
            }
            else{
                //count bhi to add kar yaha pe;
                count+=cnt-1;
                hasodd=1;
            }
        }
        if(hasodd)count++;

        return count;
    }
};