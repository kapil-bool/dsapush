class Solution {
public:
    int minPartitions(string n) {
        //closed u can get is by 11 if no 0 if 0 is at end then 10 directly 
        //but what if its is 132 111 can be the answer and so onn so how many 11 to pick maybe this is where things get intresting

        int maxi=-1e9;
        for(int i=0;i<n.size();i++){
               maxi=max(n[i]-'0',maxi);
        }
        return maxi;
    }
};
