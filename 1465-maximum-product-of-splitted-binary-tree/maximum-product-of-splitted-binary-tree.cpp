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
     static const int MOD = 1e9 + 7;
    long long valto_sum(TreeNode * node){
        //base case
        if(!node) return 0 ;
        //else
        node->val+=valto_sum(node->left)+valto_sum(node->right);


        return node->val;
    }
    int maxProduct(TreeNode* root) {
        //approch to ban gaya 
        //now should i store the sum here insted of the value in it that i can do like dfs or bfs
        //2->val(left+right) childs that to from the sub tree // dfs he lagega 
        long long total= valto_sum(root);
        queue<TreeNode*>q;
        long long ans=-1;
        q.push(root);
        while(!q.empty()){
           //root will always be a complet path
           TreeNode* tp=q.front();
           q.pop();
           //check for the elem both
           ans=max(ans,(tp->val)*(total-(tp->val)));
           if(tp->left)q.push(tp->left);
           if(tp->right)q.push(tp->right);
        }
        return ans% MOD;
    }
};