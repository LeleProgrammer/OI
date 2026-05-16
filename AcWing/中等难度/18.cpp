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
    
    map<int,int> positions;
    vector<int> pre;
    vector<int> in;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=preorder.size();
        for (int i=0;i<=len-1;++i) {
            positions[inorder[i]]=i;
        }
        this->pre=preorder;
        this->in=inorder;
        TreeNode* result=dfs(0,len-1,0,len-1);
        return result;
    }
    
    TreeNode* dfs(int pre_l,int pre_r,int in_l,int in_r) {
        if (pre_l<=pre_r) {
            int tmp=positions[pre[pre_l]]-in_l;
            TreeNode* root=new TreeNode(pre[pre_l]);
            root->left=dfs(pre_l+1,pre_l+tmp,in_l,in_l+tmp-1);
            root->right=dfs(pre_l+tmp+1,pre_r,in_l+tmp+1,in_r);
            return root;
        } else {
            return nullptr;
        }
    }
};