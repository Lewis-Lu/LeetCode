#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* CreateNode(vector<int> v){
    ListNode* root = new ListNode(0);
    ListNode*p = root;
    for(int i = 0; i < v.size(); i++){
        p->next = new ListNode(v[i]);
        p = p->next;
    }
    return root->next;
}

// ListNode* swapPairs(ListNode* head){
//     ListNode **p = &head, *ptr = NULL;
//     while ((*p) && (*p)->next) {
//         // first
//         // ptr = (*p)->next->next;
//         // (*p)->next->next = (*p);
//         // (*p) = (*p)->next;
//         // (*p)->next->next = ptr;
//         // p = &((*p)->next->next);

//     }
//     return head;
// }

ListNode* swapPairs(ListNode* head){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    while(head && head->next){
        ListNode* n = head->next->next;
        head->next->next = head;
        pre->next = head->next;
        head->next = n;
        pre = head;
        head = n;
    }
    return dummy->next;
}


int main(int argc, char const *argv[]){
    vector<int> v1 = {1, 2, 3};
    ListNode* l1 = CreateNode(v1);

    ListNode* List = swapPairs(l1);
    ListNode* p = List;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
