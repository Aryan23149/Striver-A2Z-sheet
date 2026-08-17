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
        void postorder(vector<int> & ans,TreeNode* root){
            if(root==NULL){
                return;
            }
            postorder(ans,root->left);
            postorder(ans,root->right);
            ans.push_back(root->val);
        }
        vector<int> iterative_postorder(TreeNode * root){
            vector<int> answer;// for storing the answer
    
            if(root==NULL) return answer;// handling base case
    
            stack<TreeNode *> s1,s2;// setup required for iterative post order using two stacks
            s1.push(root);
            TreeNode * top_node_s1=root;
    
            while(!s1.empty()){// repeat untill s1 is empty
    
                top_node_s1=s1.top();// take top element of s1
                s2.push(top_node_s1);// put it into s2
                s1.pop();// pop top element of s1
    
                if(top_node_s1->left){// if left element of poppped element exists then put it into s1
                    s1.push(top_node_s1->left);
                }
    
                if(top_node_s1->right){// do same with right element
                    s1.push(top_node_s1->right);
                }
    
            }
            while(!s2.empty()){// in s2 we shall be having postorder just receive it in an array
                answer.push_back(s2.top()->val);
                s2.pop();
            }
            return answer;// returning simple our answer
        }
        vector<int> postorder_using_one_stack(TreeNode * root){
            stack<TreeNode*> s;
            TreeNode* curr = root;
            vector<int> answer;
            while(curr != nullptr || !s.empty()){
                if(curr != nullptr){
                    s.push(curr);
                    curr=curr->left;
                }
                else{
                    TreeNode* temp = s.top()->right;
                    if(temp == nullptr){
                        temp = s.top();
                        s.pop();
                        answer.push_back(temp->val);
                        while(!s.empty() && temp == s.top()-> right){
                            temp = s.top();
                            s.pop();
                            answer.push_back(temp->val);
                        }
                    }
                    else{
                        curr = temp;
                    }
                }
            }
            return answer;
        }
        vector<int> postorderTraversal(TreeNode* root) {
            // recursive postorder
            // vector<int> ans;
            // postorder(ans,root);
            //return ans;
    
            // iterative postorder
            // TC: O(N) SC: O(2N)
           // return iterative_postorder(root);

            // post order traversal using one stack
             // tc: O(2N) sc: O(N)
            return postorder_using_one_stack(root);


        }
    };