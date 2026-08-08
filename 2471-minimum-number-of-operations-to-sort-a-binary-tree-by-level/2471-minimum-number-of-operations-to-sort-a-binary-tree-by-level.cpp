class Solution {
public:

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int operation = 0;

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] == sorted[i])
                continue;

            int correctPos = pos[sorted[i]];

            pos[nums[i]] = correctPos;
            pos[sorted[i]] = i;

            swap(nums[i], nums[correctPos]);

            operation++;
        }

        return operation;
    }

    int minimumOperations(TreeNode* root) {

        int ans = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int sz = q.size();
            vector<int> nums;

            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();
                nums.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            ans += minSwaps(nums);
        }

        return ans;
    }
};