#include "Tree.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    std::vector<int> data = {1,2,3,4,5,NULL,6,NULL,NULL,7,8};
    
    Tree preTree(data);
    TreeNode* root =  preTree.Build(0);
    preTree.NorecursivePreTranverse(root);

    cout << "nodes number = " << preTree.traverse_res.size() << endl;

    cout << "<pre-traverse result>" << endl;
    for (std::vector<int>::iterator i = preTree.traverse_res.begin(); i != preTree.traverse_res.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    Tree inTree(data);
    TreeNode* inroot = inTree.Build(0);
    inTree.NonrecursiveInorderTranverse(inroot);

    cout << "nodes number = " << inTree.traverse_res.size() << endl;

    cout << "<in-traverse result>" << endl;
    for(std::vector<int>::iterator i = inTree.traverse_res.begin(); i != inTree.traverse_res.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    Tree rearTree(data);
    TreeNode* rearroot = rearTree.Build(0);
    rearTree.NonrecursiveBackOrderTranverse(rearroot);

    cout << "nodes number = " << rearTree.traverse_res.size() << endl;

    cout << "<rear-traverse result>" << endl;
    for(std::vector<int>::iterator i = rearTree.traverse_res.begin(); i != rearTree.traverse_res.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    Tree levelTree(data);
    TreeNode* levelroot = levelTree.Build(0);
    levelTree.LevelOrderTranverse(levelroot);

    cout << "nodes number = " << levelTree.traverse_res.size() << endl;

    cout << "<level-traverse result>" << endl;
    for (std::vector<int>::iterator i = levelTree.traverse_res.begin(); i != levelTree.traverse_res.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    Tree zigzagLevelTree(data);
    TreeNode* zigzagroot = zigzagLevelTree.Build(0);
    zigzagLevelTree.ZigzagLevelOrderTranverse(zigzagroot);

    cout << "nodes number = " << zigzagLevelTree.traverse_res.size() << endl;

    cout << "<level-traverse result>" << endl;
    for (std::vector<int>::iterator i = zigzagLevelTree.traverse_res.begin(); i != zigzagLevelTree.traverse_res.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;


    return 0;
}
