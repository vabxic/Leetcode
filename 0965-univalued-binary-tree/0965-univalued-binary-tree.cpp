class Solution {
public:
    set<int>st;
    void dfs(TreeNode* root){
        if (root == NULL)return;

        st.insert(root ->val);
        dfs(root ->left);
        dfs(root -> right);
    }
    bool isUnivalTree(TreeNode* root) {
        dfs(root);
        return st.size() == 1;
    }
};