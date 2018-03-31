#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int max_sum;
        int maxPathSum(TreeNode* root) {
            max_sum = INT_MIN;
            goDown(root);
            return max_sum;
        }

        int goDown(TreeNode* node) {
            if (node == NULL) return 0;

            int maxsum_left = max(goDown(node->left), 0);
            int maxsum_right = max(goDown(node->right), 0);

            max_sum = max(max_sum, maxsum_left + maxsum_right + node->val);
            return max(maxsum_left, maxsum_right) + node->val;
        }
};


int main()
{
    Solution s;

    return 0;
}
