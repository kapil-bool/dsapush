class Solution {
public:
    vector<double>solver(double a,double b){
        vector<double>temp;
        temp.push_back(a+b); //no effect here also
        temp.push_back(b-a); 
        temp.push_back(a*b); //no effect here
        temp.push_back(a-b);
        // temp.push_back(a+b);
        if(fabs(b) > 1e-6) temp.push_back((double)a/b);
        if(fabs(a) > 1e-6) temp.push_back((double)b/a);
        return temp; //now computation is done here and call recursivly here

    }
    //one smart trich here is as u make take the numbers from the nums the -1 reduction every time so at last only 
    //size 1 will be left so for that [0]==24 return 1;
    bool helper(vector<double>&nums){
        if(nums.size()==1){
           return fabs(nums[0] - 24.0) < 1e-6;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                //if same u repeat it so continue alse pick the numbers
                if(i==j) continue;
                vector<double>minusone;
                for(int k=0;k<nums.size();k++){
                    //so dont take the i and j and push all other here as they will be used later here
                    if(k==i or k==j)continue;
                    else
                     minusone.push_back(nums[k]);
                     //the other one will be from the compute of a and b and themn push it here
                }

                //compute;
                for(auto value:solver(nums[i],nums[j])){
                    //push the obtained to the minusone 
                    minusone.push_back(value);
                    //now helper here for the -1 size
                    if(helper(minusone)) return true;;
                    minusone.pop_back();
                }

            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        //all possiblites try all 4 options with the number if u dont reach the end and 24 is obtained return true and break else return false;
        vector<double>nums(cards.begin(),cards.end());
        return helper(nums);
        

    }
};
//pick tw o numbers and solve recusily till u reach the end 
//if its ot the answer u backtrack 
//so the first thinging is to pick 2 numbers
//For JavaScript users, for avoiding floating point precision you can use:
// if(Math.abs(24 - candidate) < 0.00000001) return true