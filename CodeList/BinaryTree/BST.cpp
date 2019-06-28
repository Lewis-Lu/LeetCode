#include <iostream>
#include <vector>

using namespace std;


struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
    Node(int x)
    {
        data = x;
        lchild = nullptr;
        rchild = nullptr;
    }
};

class BST
{
private:
    /* data */
public:
    int searchBST(Node *root, int value, Node* parent, Node* p)
    {
        // cannot find 
        if(!root){
            p = parent; 
            return false;
        }
        // can find
        else if(root->data = value){
            p = root;
            return true;
        }
        else if(root->data > value){
            return searchBST(root->lchild, value, root, p); 
        }
        else{
            return searchBST(root->rchild, value, root, p);
        }
    }

    int insert(Node *root, int value)
    {
        Node* p = nullptr;
        Node* s  = new Node(value);

        if(!searchBST(root, value, NULL, p)){
            if(!p) root = s;
            else if(p->data > value) p->lchild = s;
            else p->rchild = s;
            return  true;
        }
        else{
            return false;
        }
    }

    void Traverse(Node* root){
        if(!root) return;
        
        Traverse(root->lchild);
        cout << root->data << " ";
        Traverse(root->rchild);
    }
};

int main(int argc, char const *argv[])
{
    BST bst;
    Node* root;
    vector<int> nums = {20,10,15,30,23,35,34,-1};
    
    for(int i = 0; i < nums.size()-1; i++) bst.insert(root, nums[i]);
    
    bst.Traverse(root);
    return 0;
}
