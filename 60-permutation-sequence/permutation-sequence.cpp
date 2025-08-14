class Solution {
public:
 vector<int>store_factorail;
string helper(int n,int k,vector<int>&dynamic){
    //lets see the groups 
    if(n==1) return to_string(dynamic[0]); //the last one here will be the answer
    //figure out how k will make the difference n is important for group till now k is like the used to pick the number so
    /* like for n=3 totoal group n-1 factorail this means i have 2 options here  but k will decide the digit i pick*/
    int group=store_factorail[n-1];
    int digi=(k-1)/group;
    string current=to_string(dynamic[digi]);
    dynamic.erase(dynamic.begin()+ digi);

    return current+helper(n-1,k-digi*group,dynamic);
    //now remove this from dyanmic;


}
    string getPermutation(int n, int k) {
        //first think is to decide the groups see eack number willl make n-1 !options /possiblites 
        //first find the grp once u finde it make vector push that into it and after that erase it from nums and try
        //obtain the output recursion will do the trick here ig 
        store_factorail.resize(n+1,1);
        for(int i=1;i<=n;i++){
            //this will be calulated simply by using the prev one
            store_factorail[i]=i*store_factorail[i-1];
            //i think this will work
        }
        //now i need an array which will resize or simply remove the one i choose 
        vector<int>dynamic;
        for(int i=1;i<=n;i++) dynamic.push_back(i);

        return helper(n,k,dynamic);

    }
};//base case when n==1