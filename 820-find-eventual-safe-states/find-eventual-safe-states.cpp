class Solution {
public:
   bool helper(int index,vector<int>& visited,vector<vector<int>>& graph){
     //its the end means no more adj from this store in visited only
     if(visited[index]==2) return true;
     if(visited[index]==1) return false; /// this is for cycle ;

     //mark them visited
     visited[index]=1;
     for(auto neighbours:graph[index]){
        if(!helper(neighbours,visited,graph)){
           return false; //this means it fails u prove it
        }
     }
     //mark it 2
     visited[index]=2;
     return true;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //i ->{graph one}
        //so avoid cycle and u are good to go 
        //so for visited 1; and as u reach the end mark it some thing
        int n=graph.size();
        vector<int>visited(n,0);
        vector<int>ans; //for storing;
        for(int i=0;i<n;i++){
            //so u traverse a indx and see if it the safe or not so must be a boolean one
            if(helper(i,visited,graph)) ans.push_back(i);
        }
        return ans; //no need to sort as cheking ffrom i->0 to n
    }
};