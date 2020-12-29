#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (vin.empty() || vin.empty())
            return nullptr;

        int index_root = 0;
        for (int i = 0; i < vin.size(); i++)
        {
            if (vin[i] == pre[0]) {
                index_root = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(pre[0]);
        vector<int> in_left, in_right;
        vector<int> pre_left, pre_right;

        for (int i = 0; i < index_root; i++)
        {
            in_left.push_back(vin[i]);
            pre_left.push_back(pre[i+1]);
        }
        
        if (index_root != vin.size()-1) {
            for (int i = index_root+1; i < vin.size(); i++)
            {
                in_right.push_back(vin[i]);
                pre_right.push_back(pre[i]);
            }
        }
        
        root->left = reConstructBinaryTree(pre_left, in_left);
        root->right = reConstructBinaryTree(pre_right, pre_left);
        return root;
    }
};