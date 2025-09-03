class Solution {
public:
int m,n;
vector<vector<int>>score;
    int ans=0;
void helper(int index,vector<bool>&visited,int currscore){
    //base csae u reached the end;
    if(index==m){
        //u reached the end 
         ans = max(ans, currscore);
        return;
    }
    //possiblites only if the visited is false;
    for (int mentor = 0; mentor < m; mentor++) {
        if(!visited[mentor]){
            visited[mentor]=1;
            helper(index+1,visited,currscore+score[index][mentor]);
            visited[mentor]=0; //mark it as unvisted 

        }
    }
}
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        //base case is u reach the end of the students in first case it is 3 
        //so here u backtrack it 
          m = students.size();
        n = students[0].size();
        score.assign(m, vector<int>(m, 0)); //put them all 0 

        for(int i=0;i<m;i++){ //student 
              for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    if(students[i][k]==mentors[j][k]) score[i][j]++;
                }
            
        }
        }
        //also the visited mark them all 0 initially
         vector<bool> visited(m, false);
         helper(0,visited,0);
        return ans;

    }
};