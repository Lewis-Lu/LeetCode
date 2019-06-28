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

ListNode* merge2Lists(ListNode *l1, ListNode *l2){
    ListNode* dummy = new ListNode(0);
    ListNode* pre = dummy;
    ListNode* p = l1;
    ListNode* q = l2;
    while(p && q){
        if(p->val <= q->val){
            pre->next = new ListNode(p->val);
            pre = pre->next;
            p = p->next;
        }else{
            pre->next = new ListNode(q->val);
            pre = pre->next;
            q = q->next;
        }
    }
    while(p){
        pre->next = new ListNode(p->val);
        pre = pre->next;
        p = p->next;
    }
    while(q){
        pre->next = new ListNode(q->val);
        pre = pre->next;
        q = q->next;
    }
    return dummy->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if(n == 0) return NULL;
    if(n == 1) return lists[0];
    vector<ListNode*> tmp;
    while(lists.size() != 1){
        for(int i = 0; i < n; i = i + 2){
            
        }
    }   
}

int main(int argc, char const *argv[]){
    vector<ListNode*> list;
    ListNode *p = CreateNode(vector<int>({1,4,5}));
    ListNode *q = CreateNode(vector<int>({1,3,4}));
    ListNode *k = CreateNode(vector<int>({2,6}));
    list.push_back(p);
    list.push_back(q);
    list.push_back(k);
    ListNode *ans = mergeKLists(list);
    ListNode *m = ans;
    while(m){
        cout << m->val << " ";
        m = m->next;
    }
    cout << endl;
    return 0;
}
