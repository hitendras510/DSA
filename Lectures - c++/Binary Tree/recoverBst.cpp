class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Check violation
                if (prev != nullptr && prev->val > curr->val) {
                    if (first == nullptr) {
                        first = prev;
                    }
                    second = curr;
                }
                prev = curr;

                curr = curr->right;
            } else {
                // Find inorder predecessor (IP)
                TreeNode* ip = curr->left;
                while (ip->right != nullptr && ip->right != curr) {
                    ip = ip->right;
                }

                if (ip->right == nullptr) {
                    // Make thread
                    ip->right = curr;
                    curr = curr->left;
                } else {
                    // Thread exists -> revert changes
                    ip->right = nullptr;

                    // Check violation
                    if (prev != nullptr && prev->val > curr->val) {
                        if (first == nullptr) {
                            first = prev;
                        }
                        second = curr;
                    }
                    prev = curr;

                    curr = curr->right;
                }
            }
        }

        // Swap values of the two corrupted nodes
        if (first != nullptr && second != nullptr) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};
