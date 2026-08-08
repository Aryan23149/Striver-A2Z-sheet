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
        vector<int> iterative_inorder(TreeNode* root){
            vector<int> ans;
            stack<TreeNode*> s;
            TreeNode * top_node=root;
            if(root==NULL) return ans;
            while(true){
                if(top_node!=NULL){
                    s.push(top_node);
                    top_node=top_node->left;
                }
                else{
                    if(s.empty()){
                        break;
                    }
                    top_node=s.top();
                    s.pop();
                    ans.push_back(top_node->val);
                    top_node=top_node->right;
                }
            }
            return ans;
        }
        void inorder(vector <int> & ans,TreeNode* root){
            if(root==NULL){
                return;
            }
            inorder(ans,root->left);
            ans.push_back(root->val);
            inorder(ans,root->right);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            // tc : O(N)
            // sc : O(N)
            // vector<int> ans;
            // inorder(ans,root);
            // return ans;
    
            // iterative inorder 
            return iterative_inorder(root);
        }
    };