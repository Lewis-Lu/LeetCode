#ifndef TREE_H
#define TREE_H

#include <vector>
#include <stack>
#include <queue>
#include <deque>

using Type_TreeNode = int;

class TreeNode
{

public:
    /* data */
    Type_TreeNode val;
    TreeNode* lchild;
    TreeNode* rchild;
public:
    TreeNode() =  default;
    TreeNode(const Type_TreeNode &v): val(v), lchild(nullptr), rchild(nullptr) {};
};


class Tree
{
private:
    std::vector<Type_TreeNode> tree_data;
    
public:
    std::vector<Type_TreeNode> traverse_res;

    Tree() = default;
    Tree(std::vector<Type_TreeNode> data): tree_data(data) {};
    TreeNode* Build(std::vector<Type_TreeNode>::size_type);

    // Tranverse
    void PreTranverse(TreeNode*);
    void NorecursivePreTranverse(TreeNode*); // use stack
    void InOrderTranverse(TreeNode*);
    void NonrecursiveInorderTranverse(TreeNode*); // use stack
    void BackOrderTranverse(TreeNode*);
    void NonrecursiveBackOrderTranverse(TreeNode*); // use stack
    void LevelOrderTranverse(TreeNode*); //use queue
    std::vector< std::vector<TreeNode*>> ZigzagLevelOrderTranverse(TreeNode*); // use deque
};

class AVL{
//TODO please finish AVL
};

inline 
TreeNode* 
Tree::Build(std::vector<Type_TreeNode>::size_type index)
{
    if (index >= tree_data.size())
        return nullptr;
    if (NULL == tree_data[index])
        return nullptr;
    TreeNode *head = new TreeNode(tree_data[index]);
    head->lchild = Build(index*2 + 1);
    head->rchild = Build(index*2 + 2);
    return head;
}

void
Tree::NorecursivePreTranverse(TreeNode* root)
{
    std::stack<TreeNode*> Stack; // set up stack for root reserve
    TreeNode* p = root; // set up cursor
    while (p || !Stack.empty())
    {
        while (p)
        {
            traverse_res.push_back(p->val);
            Stack.push(p);
            p = p->lchild;
        }
        if (!Stack.empty())
        {
            p = Stack.top();
            Stack.pop();
            p = p->rchild;
        }
    }
}

// pre-order recursive
void
Tree::PreTranverse(TreeNode* root)
{
    if (!root) return;
    traverse_res.push_back(root->val);
    PreTranverse(root->lchild);
    PreTranverse(root->rchild);
}

void
Tree::NonrecursiveInorderTranverse(TreeNode* root)
{
    std::stack<TreeNode*> Stack;
    TreeNode* p = root;
    while (p || !Stack.empty())
    {
        while (p)
        {
            Stack.push(p);
            p = p->lchild;
        }

        if (!Stack.empty())
        {
            p = Stack.top();
            traverse_res.push_back(p->val);
            Stack.pop();
            p = p->rchild;
        }
        
    }
    
}

// in-order recursive
void
Tree::InOrderTranverse(TreeNode* root)
{
    if(!root) return;
    InOrderTranverse(root->lchild);
    traverse_res.push_back(root->val);
    InOrderTranverse(root->rchild);
}

void
Tree::NonrecursiveBackOrderTranverse(TreeNode* root)
{
    std::stack<TreeNode*> Stack;
    TreeNode* p = root;
    TreeNode* lastvisit = root;

    while (p || !Stack.empty())
    {
        while (p)
        {
            Stack.push(p);
            p = p->lchild;
        }
        
        p = Stack.top();

        if (!p->rchild || p->rchild == lastvisit)
        {
            traverse_res.push_back(p->val);
            Stack.pop();
            lastvisit = p;
            p = nullptr;
        }
        else
        {
            p = p->rchild;
        }
    }
}

// back-order recursive
void
Tree::BackOrderTranverse(TreeNode* root)
{
    if(!root) return;
    BackOrderTranverse(root->lchild);
    BackOrderTranverse(root->rchild);
    traverse_res.push_back(root->val);
}

// level-order traversal
void
Tree::LevelOrderTranverse(TreeNode* root)
{
    std::queue<TreeNode*> Queue;
    TreeNode* p = root;
    Queue.push(p);
    while (!Queue.empty())
    {
        TreeNode* tmp = Queue.front();
        traverse_res.push_back(tmp->val);
        Queue.pop();
        if (tmp->lchild)
            Queue.push(tmp->lchild);
        if (tmp->rchild)
            Queue.push(tmp->rchild);
    }
}

// zigzag level-order traversal
std::vector< std::vector<TreeNode*>>
Tree::ZigzagLevelOrderTranverse(TreeNode* root)
{
    
    TreeNode* p = root;
    std::vector< std::vector<TreeNode*>> ans;
    
    std::vector<TreeNode*> oneLevel;
    oneLevel.push_back(p);
    ans.push_back(oneLevel);

    bool isReverse = true;

    while (!oneLevel.empty())
    {
        
    }
    

    return ans;    
}

#endif