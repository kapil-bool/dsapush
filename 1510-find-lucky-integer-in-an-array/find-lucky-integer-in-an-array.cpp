class Solution {
public:
    int findLucky(vector<int>& arr) {
        //create a vector store the values in it o(n) to waha do a linear sezrch and return the value if index==xount[index]
        vector<int>count(501,0);

        for(int i=0;i<arr.size();i++){
            int index_tobepushed=arr[i];
            count[index_tobepushed]++;
        }
        int val=-1;
        for(int i=1;i<count.size();i++){
            if(i==count[i]) val=i;
        }
        return val;
    }
};