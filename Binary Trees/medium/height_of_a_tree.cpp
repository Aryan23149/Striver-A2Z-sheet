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
        int maxDepth(TreeNode* root) {
    
            // recursive approach
    
            // tc : O(N) sc : O(N) as max depth of recursion is directly proportional to height of tree which can be N in case of skewed tree
    
            // if(root==nullptr){
            //     return 0;
            // }
    
            // int h1=maxDepth(root->left);
            // int h2=maxDepth(root->right);
    
            // return max(h1,h2)+1;
    
            // iterative appraoch using queue
    //        Complexity Analysis
            // Time Complexity: O(N), each node is processed once in Level Order Traversal.
            // Space Complexity: O(N), in worst case, a maximum of N/2 nodes can be present in queue.
    
    
            int count =0;
    
            if(root==NULL) return 0;// base case
    
            queue<TreeNode*> q;// we need a queue
            q.push(root);// enter our root node in it
    
            while(!q.empty()){// while q has elements keep going
                int n = q.size();// what is size of queue right now or how many elements are there in current level
                for(int i=0;i<n;i++){// for all the elements in the current level
                    TreeNode * node = q.front();// a pointer to point elements of a queue
                    q.pop();// remove this element from the queue as it has no usse now
                    if(node->left!=NULL){// if left_element exists then put it into queue
                        q.push(node->left);
                    }
                    if(node->right!=NULL){// if right_element exists then put it into queue
                        q.push(node->right);
                    }
                }
                count++;
            }
            return count;
        }
    };