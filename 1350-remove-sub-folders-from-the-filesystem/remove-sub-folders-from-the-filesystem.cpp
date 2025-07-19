class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        //so for this csort and compare it compre will be like the prev elemnt there in the ans error and / and compare it if 
        //if u find it u just cont push it and continue the search
        vector<string>ans;
        sort(folder.begin(),folder.end());
        //push the first one manulally 
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
           //compare function
           string temp=ans.back();
           if(folder[i].substr(0,temp.size()+1)!=temp+"/"){
              ans.push_back(folder[i]);
           }
            
        }
        return ans;

    }
};