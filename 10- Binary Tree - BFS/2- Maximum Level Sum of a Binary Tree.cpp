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
#define ll long long
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q ;
        q.push(root);
        ll maxi = -1e6 ;
        int maxLevel = 0;
        int level = 1 ; 
        while (!q.empty()) {
            int nodes = q.size();
            ll sum = 0 ;
            for (int i = 1 ; i <= nodes ; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (!curr)
                    continue;

                if(curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                sum += curr->val ;
            }
            if (maxi < sum) {
                maxi = sum ;
                maxLevel = level ;
            }
            level++ ; 
        }
        return maxLevel ;
    }
};