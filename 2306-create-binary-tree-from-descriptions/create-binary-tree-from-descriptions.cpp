/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
        unordered_map<int,int> parentleft;
        unordered_map<int,int> parentright;
    TreeNode* build(int nodeval){
        if(!nodeval){
            return nullptr;
        }
        TreeNode *root=new TreeNode(nodeval);
        //left and right dfs traversal implntation;
        if(parentleft.count(nodeval)){
            //passs the left child value here
              root->left=build(parentleft[nodeval]);
        } 
        if(parentright.count(nodeval)){
            //passs the left child value here
              root->right=build(parentright[nodeval]);
        } 
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        //create the parent and child relation 
        //crete adj list here 
        int n=descriptions.size();
        unordered_set<int>childs;
        int tpcondender;
         for(auto &i:descriptions){
            int parent=i[0];
            int child=i[1];
            int whichside=i[2];
            childs.insert(child);
            //  int current=i;
             if(whichside==1){
                // leftone
                  parentleft[parent]=child;

             }
             else if(whichside==0){
                 parentright[parent]=child;
             }
             //the one which dont have a parent is the top of head do a  dfs here and return thr TreeNode *
         }

          for(auto&i:descriptions){
             if(childs.find(i[0])==childs.end()){
                tpcondender=i[0];
                break;
             }
          }

          return build(tpcondender);
        
    }
};