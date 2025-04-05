class Solution {

    private:
    void genereatesubset(vector<int>& nums,vector<vector<int>> &subset,int index,vector<int>& sub){

        if(index==nums.size()){
            subset.push_back(sub);
            return;
        }
        //two options is what i have 
        // ether select or not select
        sub.push_back(nums[index]); //starting wala;
        genereatesubset(nums,subset,index+1,sub);//with nums of i
        sub.pop_back();
        genereatesubset(nums,subset,index+1,sub); //without nums of i

    }
    public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>sub;
        //call the function()
        genereatesubset(nums,subset,0,sub);
        // now do the manipulation on the subset array assay it have all your sub formed
        int ans=0;
        for(auto &i : subset){
            int xorr=0;
            for(auto & j: i){
                 xorr^=j;
            }
            ans+=xorr;
        }
        return ans;

    }
};