#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* head = nullptr;

ListNode* CreateNode(vector<int> v){
    ListNode* root = new ListNode(0);
    ListNode*p = root;
    for(int i = 0; i < v.size(); i++){
        p->next = new ListNode(v[i]);
        p = p->next;
    }
    return root->next;
}

ListNode* reverse(ListNode* p){
    
}

void ReversePrint(ListNode *p){
    if(p == nullptr){
        return;
    }
    ReversePrint(p->next);
    cout << p->val << endl;
}

int main(int argc, char const *argv[]){
    vector<int> v = {1,2,3,4,5};
    ListNode* L = CreateNode(v);
    ReversePrint(L);
    return 0;
}
