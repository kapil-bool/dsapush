class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //use binary here on the basis portion
        sort(potions.begin(),potions.end());
        int n=spells.size();
        vector<int>ans; //n,0 if u want 
        int m=potions.size();
        for(int i=0;i<n;i++){
             int start=0;
             int end=m-1;
             int temp=0;
            //find the first one max where it is not making the condtion fullfill
             while(start<=end){
                int mid=(start+end)/2;
                long long product = 1LL * potions[mid] * spells[i];
                if(product>=success){
                    //valiid hai 
                    temp=max(temp,(m-mid));
                    end=mid-1;
                    //this will be finding a new mid and updating it 
                }
                else{
                    start=mid+1;
                }

             }
             ans.push_back(temp); //valid wale aa gaye sare

        }
        return ans;
    }
};