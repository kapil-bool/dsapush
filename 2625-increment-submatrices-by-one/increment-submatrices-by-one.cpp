class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        //pk now i know what it the question is saying
     vector<vector<int>> differ(n + 1, vector<int>(n + 1, 0)); 
     //most negative can be -1 boundery make sure here bf is a tle here 
      //first make the differ one fill with the queries here
       for(auto &i :queries){
          int r1=i[0];
          int c1=i[1],c2=i[3],r2=i[2];
          //start filling now 
           if (r2 + 1 < n + 1) differ[r2 + 1][c1] -= 1;
            if (c2 + 1 < n + 1) differ[r1][c2 + 1] -= 1;
            if (r2 + 1 < n + 1 && c2 + 1 < n + 1)
                differ[r2 + 1][c2 + 1] += 1;
          differ[r1][c1]+=1; //start of the boundary
        //   differ[r2+1][c1]=-1; //here out of bound may be posaaible 
        //   differ[r1][c2+1]=-1; //end here simaly hte above one also
        //   //common one make it already one as when u will be doing up and down it will be -2;
        //   differ[r2+1][c2+1]+=1;
       }
       //row operation
       for(int i=0;i<n;i++){
           for(int j=1;j<n;j++){
             differ[i][j]+=differ[i][j-1]; //previos col in same row that it
           }
       }
       //col operation same
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                differ[i][j] += differ[i - 1][j];
            }
        }
          vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                result[i][j] = differ[i][j];

        return result;
    }
}; //dammm this one is actaully some thing new 