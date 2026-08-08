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
        void preorder(vector<int> & ans,TreeNode* root){
            if(root==NULL){
                return ;
            }
            ans.push_back(root->val);
            preorder(ans,root->left);
            preorder(ans,root->right);
        }
        vector<int> iterative_preorder_traversal(TreeNode * root){
            if(root==NULL){
                return {};
            }
            vector<int> ans;
            stack<TreeNode*> s;
            s.push(root);
            while(!s.empty()){
                TreeNode * top_element=s.top();
                s.pop();
                if(top_element->right!=NULL){
                    s.push(top_element->right);
                }
                if(top_element->left!=NULL){
                    s.push(top_element->left);
                }
                ans.push_back(top_element->val);
            }
            return ans;
        }
        vector<int> preorderTraversal(TreeNode* root) {
            // recursive_preorder_traversal 
            // tc : O(N) sc : O(N)
            // vector<int> ans;
            // preorder(ans,root);
            // return ans;
    
            // tc : O(N) sc : O(N)
            return iterative_preorder_traversal(root);
        }
    };