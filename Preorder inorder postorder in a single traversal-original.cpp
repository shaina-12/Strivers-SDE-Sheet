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
void getPreorder(TreeNode *root, vector<int> &preorder){
    if(root==NULL){
        return;
    }
    preorder.push_back(root->data);
    getPreorder(root->left, preorder);
    getPreorder(root->right, preorder);
}
void getInorder(TreeNode *root, vector<int> &inorder){
    if(root==NULL){
        return;
    }
    getInorder(root->left, inorder);
    inorder.push_back(root->data);
    getInorder(root->right, inorder);
}
void getPostorder(TreeNode *root, vector<int> &postorder){
    if(root==NULL){
        return;
    }
    getPostorder(root->left, postorder);
    getPostorder(root->right, postorder);
    postorder.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> preorder, inorder, postorder;
    getPreorder(root, preorder);
    getInorder(root, inorder);
    getPostorder(root, postorder);
    vector<vector<int>> result;
    result.push_back(inorder);
    result.push_back(preorder);
    result.push_back(postorder);
    return result;
}
