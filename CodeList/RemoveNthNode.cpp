#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

vector<int> v = {1};

ListNode* CreateNode(){
    ListNode* root = new ListNode(0);
    ListNode*p = root;
    for(int i = 0; i < v.size(); i++){
        p->next = new ListNode(v[i]);
        p = p->next;
    }
    return root->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode* front = dummy;
    ListNode* rear = dummy;
    int len = 0;
    while(rear->next != NULL){
        len++;
        rear = rear->next;
    }
    for(int i = 0; i < len-n; i++){
        front = front->next;
    }
    front->next = front->next->next;
    return dummy->next;
}

int main(int argc, char const *argv[]){
    ListNode* a = CreateNode();
    ListNode* data = removeNthFromEnd(a,1);
    ListNode* p = data;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
