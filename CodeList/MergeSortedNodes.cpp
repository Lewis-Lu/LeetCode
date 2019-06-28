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

// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
//     ListNode* dummy = new ListNode(0);
//     ListNode* pre = dummy;
//     ListNode* p = l1;
//     ListNode* q = l2;
//     while(p && q){
//         if(p->val <= q->val){
//             pre->next = new ListNode(p->val);
//             pre = pre->next;
//             p = p->next;
//         }else{
//             pre->next = new ListNode(q->val);
//             pre = pre->next;
//             q = q->next;
//         }
//     }
//     while(p){
//         pre->next = new ListNode(p->val);
//         pre = pre->next;
//         p = p->next;
//     }
//     while(q){
//         pre->next = new ListNode(q->val);
//         pre = pre->next;
//         q = q->next;
//     }
//     return dummy->next;
// }

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode* ans;
    
    // base cases
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    //select either a or b and recur
    if(l1->val <= l2->val){
        ans = l1;
        ans->next = mergeTwoLists(l1->next, l2);
    }else{
        ans = l2;
        ans->next = mergeTwoLists(l1, l2->next);
    }
    return ans;
}

int main(int argc, char const *argv[]){
    vector<int> v1 = {1, 2, 4};
    vector<int> v2 = {1, 3, 4}; 
    ListNode* l1 = CreateNode(v1);
    ListNode* l2 = CreateNode(v2);

    ListNode* Sort = mergeTwoLists(l1,l2);
    ListNode* p = Sort;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
