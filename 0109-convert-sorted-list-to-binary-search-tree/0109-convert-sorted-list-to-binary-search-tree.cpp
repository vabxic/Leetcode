/*
approach 2

class Solution {
public:
    TreeNode* convertToBST(ListNode* start, ListNode* end){
        if(start == end) return nullptr;
        ListNode* slow = start;
        ListNode* fast = start;

        while(fast!=end && fast->next!=end){
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* head = new TreeNode(slow->val);
        head->left = convertToBST(start, slow);
        head->right = convertToBST(slow->next, end);
        return head;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        return convertToBST(head, nullptr);
    }
};
*/

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