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
    int maxLevelSum(TreeNode* root) {
        //bfs traversal will do the trick ig
        queue<TreeNode *> q;
        q.push(root);
        int ans=INT_MIN;
        int level=0;
        int levelcompare=-1;
        
        while(!q.empty()){
           int tempsum=0;
           int qsize=q.size();
           level++;
           for(int i=0;i<qsize;i++){
           TreeNode* tp=q.front();

           tempsum+=tp->val;
           q.pop();
           if(tp->left){
             q.push(tp->left);
           }
           if(tp->right){
             q.push(tp->right);
           }
        
           }
           //now compare the sum also
           if(ans<tempsum){
               levelcompare=level;
               ans=tempsum;
           }
           
        }
        return levelcompare;
    }
};