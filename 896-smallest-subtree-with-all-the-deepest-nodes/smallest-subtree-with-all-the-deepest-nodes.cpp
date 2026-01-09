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
 pair<TreeNode* ,int>dfs(TreeNode * root){
         if(!root) return {nullptr,0};
         auto left=dfs(root->left);
         auto right=dfs(root->right);
          //i need code to find ancestor  also 
          //till the children lenth is same
          if(left.second> right.second){
            //  left side wale pe move karo ji
             return {left.first,left.second+1};
          }
          if(left.second<right.second){
            //  left side wale pe move karo ji
             return {right.first,right.second+1};
          }
          //else ==
          return {root,left.second +1};
         
       }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //depest nodes ka lca chaiye 
        //need depth and the parent to it
    //    pair<TreeNode* ,int>dfs(TreeNode * root){
    //      if(!root) return {nullptr,0};
    //      auto left=dfs(node->left);
    //      auto right=dfs(node->right);
    //       //i need code to find ancestor  also 
    //       //till the children lenth is same
    //       if(left.second> right.second){
    //         //  left side wale pe move karo ji
    //          return ({left.first,left.second+1});
    //       }
    //       if(left.second<right.second){
    //         //  left side wale pe move karo ji
    //          return ({right.first,right.second+1});
    //       }
    //       //else
    //       return ({root,root->left.second});
         
    //    }
        return dfs(root).first;
    }
};