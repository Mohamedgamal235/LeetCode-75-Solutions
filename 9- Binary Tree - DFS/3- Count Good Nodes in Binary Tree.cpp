class Solution {
public:
    void solve(TreeNode* root , int maxi , int &cnt) {
        if(!root)
            return;
        if (root->val >= maxi) {
            cnt++ ;
            maxi = root->val;
        }
        solve(root->left , maxi , cnt);
        solve(root->right , maxi , cnt);
    }

    int goodNodes(TreeNode* root) {
        int maxi = INT_MIN , cnt = 0 ;
        solve(root , maxi , cnt);
        return cnt ;
    }
};