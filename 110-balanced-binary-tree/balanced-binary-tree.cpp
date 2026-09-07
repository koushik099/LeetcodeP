/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int calcHeight(TreeNode* root, vector<int>& leftHeight,
                   vector<int>& rightHeight) {

        if (!root) {
            return 0;
        }

        int heightOfLeft = calcHeight(root->left, leftHeight, rightHeight);
        int heightOfRight = calcHeight(root->right, leftHeight, rightHeight);

        leftHeight.push_back(heightOfLeft);
        rightHeight.push_back(heightOfRight);

        return 1 + max(heightOfLeft, heightOfRight);
    }

    bool isBalanced(TreeNode* root) {

        vector<int> leftHeight;
        vector<int> rightHeight;

        calcHeight(root, leftHeight, rightHeight);

        for (int i = 0; i < leftHeight.size(); i++) {

            if (abs(leftHeight[i] - rightHeight[i]) > 1) {
                return false;
            }
        }

        return true;
    }
};