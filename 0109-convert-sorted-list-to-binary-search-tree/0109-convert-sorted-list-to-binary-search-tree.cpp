// approach 1
class Solution {
public:
    vector<int> listToVector(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next; // sorted LL to sorted vector
        }
        return nums;
    }
    TreeNode* buildBST(vector<int>& nums, int st, int end) {
        if (st > end)return nullptr;
        
        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, st, mid - 1); // sorted vector to BST
        root->right = buildBST(nums, mid + 1, end);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec = listToVector(head);
        return buildBST(vec, 0, vec.size() - 1);
    }
};