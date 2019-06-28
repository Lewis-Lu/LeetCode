#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

 

struct TNode{
    int val;
    TNode* left;
    TNode* right;
    TNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

int max(int a, int b, int c){
    return max(max(a,b),c);
}

int findMaxPath(TNode *root, int sum);
int findMinPath(TNode *root, int sum);

// for binary tree, use recursive way to build it.
// 2*i+1 for left child
// 2*i+2 for right child
TNode* BuildBinaryTree(vector<int>& nums, TNode* root, int i, int n){

    if(i < n){
        TNode* tmp = new TNode(nums[i]);
        root = tmp;

        root->left = BuildBinaryTree(nums, root->left, 2*i+1, n);
        root->right = BuildBinaryTree(nums, root->right, 2*i+2, n);
    }
    return root;
}

void Traverse(TNode* root){
    if(!root) return;

    Traverse(root->left);
    cout << root->val << endl;
    Traverse(root->right);

}

int findMax(TNode *root){
    // sub problem case
    if(!root) return INT_MIN;

    // return maximum of 3 values
    // max(max(left_subtree),  max(right_subtree), root)
    int v = root->val;
    int lv = findMax(root->left);
    int rv = findMax(root->right);

    v = max(v, lv, rv);
    return v;
}

int findMaxPath(TNode *root){
    return findMaxPath(root, 0);
}

int findMinPath(TNode *root){
    return findMinPath(root, 0);
}

int findMaxPath(TNode *root, int sum){
    if(!root) return 0;
    
    int value = root->val;
    int l_sum, r_sum;
    l_sum = findMaxPath(root->left, l_sum);
    r_sum = findMaxPath(root->right, r_sum);

    sum = max(l_sum, r_sum) + value;
    return sum;
}

int findMinPath(TNode *root, int sum){
    if(!root) return 0;
    
    int value = root->val;
    int l_sum, r_sum;
    l_sum = findMaxPath(root->left, l_sum);
    r_sum = findMaxPath(root->right, r_sum);

    sum = min(l_sum, r_sum) + value;
    cout << sum << endl;
    return sum;
}


int main(int argc, char const *argv[]){
    vector<int> nums = {-10, 9, -20, 22, 4, -15, 7};   
    TNode* bt = BuildBinaryTree(nums, bt, 0, nums.size());
    // Traverse(bt);
    cout << findMinPath(bt) << endl;
    return 0;
}
