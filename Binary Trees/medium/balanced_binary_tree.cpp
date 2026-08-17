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
        int height_of_a_tree(TreeNode* root){
            if(root==nullptr){
                return 0;
            }
            return max(height_of_a_tree(root->left),height_of_a_tree(root->right))+1;
        }
        bool check(TreeNode* node){
            if(node==nullptr) return true;
    
            int l = height_of_a_tree(node->left);
            int r= height_of_a_tree(node->right);
    
            if(abs(l-r)>1) return false;
    
            bool left = check(node->left);
            bool right = check(node->right);
    
            if(!(left && right)) return false;
            return true;
        }
        bool optimalIsBalanced(TreeNode * node){
            int x = optimalCheck(node);
            if(x==-1) return false;
            return true;
        }
        int optimalCheck(TreeNode* node){
            if(node==nullptr) return 0;
            int lh= optimalCheck(node->left);
            if(lh==-1) return -1;
            int rh = optimalCheck(node->right);
            if(rh==-1) return -1;
            if(abs(lh-rh)>1) return -1;
            return max(lh,rh)+1;
        }
        bool isBalanced(TreeNode* root) {
            // extremely naive solution
            // for each node we calculate its left tree and right tree height which takes O(N) time and space for each node and since there are N nodes total tc : O(N*N) and Sc: O(N*N)
            //return check(root);
    
            return optimalIsBalanced(root);
        }
    };