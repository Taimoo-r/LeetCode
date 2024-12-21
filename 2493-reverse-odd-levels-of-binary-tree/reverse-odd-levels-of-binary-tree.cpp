class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr; // Base case: if the tree is empty

        queue<TreeNode*> q;
        q.push(root);
        bool isOddLevel = false;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<TreeNode*> levelNodes;

            // Collect all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                levelNodes.push_back(curr);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // Reverse the values of nodes at odd levels
            if (isOddLevel) {
                int left = 0, right = levelNodes.size() - 1;
                while (left < right) {
                    swap(levelNodes[left]->val, levelNodes[right]->val);
                    ++left;
                    --right;
                }
            }

            // Toggle the level type
            isOddLevel = !isOddLevel;
        }

        return root;
    }
};
