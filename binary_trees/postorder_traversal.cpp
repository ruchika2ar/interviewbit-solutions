/*
Given a binary tree, return the postorder traversal of its nodes’ values.
Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> v(0);
    if (!A) return v;
    stack<TreeNode*> s;
    stack<bool> l;
    stack<bool> r;
    s.push(A);
    l.push(false); r.push(false);
    while (!s.empty()) {
        TreeNode* cur = s.top();
        if (!l.top()) {
            l.pop();
            l.push(true);
            if (cur->left){
                s.push(cur->left);
                l.push(false);
                r.push(false);
            }
        } else if (!r.top()) {
            r.pop();
            r.push(true);
            if (cur->right) {
                s.push(cur->right);
                l.push(false);
                r.push(false);
            }
        } else {
            v.push_back(cur->val);
            s.pop();
            l.pop();
            r.pop();
        }
    }
    return v;
}
