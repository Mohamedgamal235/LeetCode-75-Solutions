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
    ll DFS(TreeNode* root , ll target , ll currSum , unordered_map<ll ,ll>& prefix) {
        if (!root)
            return 0;

        currSum += root->val;
        ll cnt = prefix[currSum - target];

        prefix[currSum]++;
        cnt += DFS(root->left , target , currSum , prefix);
        cnt += DFS(root->right , target , currSum , prefix);

        prefix[currSum]-- ;
        if (prefix[currSum] == 0)
            prefix.erase(currSum);

        return cnt ; 
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll , ll> prefix ;
        prefix[0] = 1 ;
        return DFS(root , targetSum , 0 , prefix);
    }
};