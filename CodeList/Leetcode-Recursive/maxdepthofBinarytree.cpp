#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(int x)
    {
        val = x;
        lchild = NULL;
        rchild = NULL;
    }
};

class Solution
{
private:

public:
    int maxDepth(TreeNode *root)
    {
        if(root != NULL) cout << root->val << endl;
        return (root == NULL) ? 0 : max(maxDepth(root->lchild), maxDepth(root->rchild)) + 1;
    }
};

TreeNode *CreateTree(vector<int> &nums, TreeNode *root, int i, int n)
{

    if (i < n)
    {
        TreeNode *tmp = new TreeNode(nums[i]);
        root = tmp;

        root->lchild = CreateTree(nums, root->lchild, 2 * i + 1, n);
        root->rchild = CreateTree(nums, root->rchild, 2 * i + 2, n);
    }
    return root;
}

void Traverse(TreeNode *root)
{
    if (!root)
        return;

    Traverse(root->lchild);
    cout << root->val << endl;
    Traverse(root->rchild);
}

int main(int argc, char const *argv[])
{
    vector<int> data = {3, 9, 20, NULL, NULL, 15, 7};
    int n = data.size();
    TreeNode *root = CreateTree(data, root, 0, n);

    Solution s;
    cout << s.maxDepth(root) << endl;

    return 0;
}
