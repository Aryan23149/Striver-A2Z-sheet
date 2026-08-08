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
        vector<vector<int>> levelOrder(TreeNode* root) {
    
            // time complexity:O(N) each node is being visited once 
            // space complexity:O(N+N+N) for queue q and level vector and level_order_traversal for storing final answers
            vector<vector<int>> level_order_traversal; // this stores our answer
            if(root==NULL) return level_order_traversal;// base case
            queue<TreeNode*> q;// we need a queue
            q.push(root);// enter our root node in it
            while(!q.empty()){// while q has elements keep going
                int n = q.size();// what is size of queue right now or how many elements are there in current level
                vector<int> level;// it stores elements of a level
                for(int i=0;i<n;i++){// for all the elements in the current level
                    TreeNode * node = q.front();// a pointer to point elements of a queue
                    q.pop();// remove this element from the queue as it has no usse now
                    if(node->left!=NULL){// if left_element exists then put it into queue
                        q.push(node->left);
                    }
                    if(node->right!=NULL){// if right_element exists then put it into queue
                        q.push(node->right);
                    }
                    level.push_back(node->val);// push it into level
                }
                level_order_traversal.push_back(level);// push entire level into the vector<vector<int>>
            }
            return level_order_traversal;
        }
    };