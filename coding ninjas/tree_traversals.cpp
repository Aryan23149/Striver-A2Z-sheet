/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here
    stack<pair<TreeNode*,int>> s;
    s.push({root,1});
    vector<vector<int>> ans(3);
    while(!s.empty()){
        TreeNode * top = s.top().first;
        int number = s.top().second;
        if(number==1){
            ans[1].push_back(top->data);
            s.top().second++;
            if(top->left!=nullptr){
                s.push({top->left,1});
            }
        }
        else if(number==2){
            ans[0].push_back(top->data);
            s.top().second++;
            if(top->right!=nullptr){
                s.push({top->right,1});
            }
        }
        else{
            ans[2].push_back(top->data);
            s.pop();
        }
    }
    return ans;
}