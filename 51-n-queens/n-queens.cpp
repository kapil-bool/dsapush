class Solution {
public:
vector<vector<string>>ans;
vector<string>temp;
//index is for the next row so i plus+1 once i put a queen if deadend is notices  i track it back
void helper(int index,int n, vector<bool> &col_check, vector<bool>& diagnol_r,vector<bool>& diagnol_l){;
    if(index==n){
        //this means i reach the eand it is akll good
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        //check for the avaliablty first the cola and diagnols 
        //push only if available (the quuen)
        //should i make it 2 like cola and row
        if(col_check[i]|| diagnol_r[index - i + n - 1] || diagnol_l[index+i]) continue;
        temp[index][i]='Q';
        col_check[i] = diagnol_r[index - i + n - 1] = diagnol_l[index+i]=1;
        //make them true for the 3 apra
        //now call it back index ++
        helper(index+1,n,col_check,diagnol_r,diagnol_l);
        temp[index][i]='.'; //back to other explaoration and make them false
        col_check[i] = diagnol_r[index - i + n - 1] = diagnol_l[index+i]=0;
    }

}
    vector<vector<string>> solveNQueens(int n) {
        temp.clear();
        temp.assign(n,string(n,'.'));
        //4 possible moves are  there which i can make diagnl both col and row 
        //sine row is index col i can use it like if the col of initally is same that to the current one dont ,make a move 
        // all i  have to figure out is the diagnol and col with the current
        vector<bool>col_check(n,0); //colums to same 
        vector<bool>diagonl_r(2*n-1,0); //for 3 its 2 for 4 its 3 so just like i 
        vector<bool>diagonl_l(2*n-1,0);
        helper(0,n,col_check,diagonl_r,diagonl_l);
        return ans;
        //so i need function for col and adj diagnols that it 
    }
};