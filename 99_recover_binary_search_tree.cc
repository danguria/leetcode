#include <iostream>
using namepace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *first;
    TreeNode *second;
    TreeNode *prev;

    Solution() {
        first = 0;
        second = 0;
        prev = new TreeNode(INT_MIN);
    }

    void recoverTree(TreeNode* root) {
        findNode(root);

        // recover
        if (first == 0 || second == 0) {
            cout << "something wrong" << endl;
        }

        swap(first->val, second->val);
    }

    void findNode(TreeNode* cur) {
        if (cur == 0) return;

        findNode(cur->left);
        if (first == 0 && cur->val < prev->val) {
            first = prev;
        }

        if (first != 0 && cur->val < prev->val) {
            second = cur;
        }
        prev = cur;
        findNode(cur->right);
    }
};

