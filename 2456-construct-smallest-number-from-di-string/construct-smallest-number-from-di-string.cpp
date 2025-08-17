class Solution {
public:
    vector<bool>visited;
    string ans;
    void helper(int index,string & pattern,string & path){
        //base case
        if(index==pattern.size()+1) {
            //some more steps here
            //ans is the answer of my code here ans>path ans=path 
            if (ans == "" || path < ans) ans = path;
            return;
        }
        //2 condtions I and D handeling 
        for(int i=1;i<=pattern.size()+1;i++){
            //always will be 1 to 9 digits as cant be more than 8
             if(!visited[i]){
                //procede check the value at index and make the move
                ///2 cases here
                //if the prev is I the curretn index should be bigger than the i here to maake iteration from it
               if (index == 0 ||(pattern[index-1] == 'I' && path.back() < '0' + i) ||(pattern[index-1] == 'D' && path.back() > '0' + i)){


                visited[i]=true;
                //push it 
                path.push_back('0'+i);
                helper(index+1,pattern,path);
                path.pop_back(); //now will explore from other
                visited[i]=false;
                //so here what i am doing is actullay exporing all the possible paths
                }

                
             
             }
        }
        // return ans;
    }
    string smallestNumber(string pattern) {
        ans=""; //ok now push into this
        visited.assign(10, false);
        string path="";
         helper(0,pattern,path);
         return ans;
        
    }
};
//1 <= pattern.length <= 8 to small constrains so no problem here 
//so use a bool vector  to store the used one and maniplute accordingly;
//n+1 will be the answer;