#include <iostream>
#include <stdio.h>

using namespace std;

#define N 3
#define M 3

int list1[N] = {2, 4, 3};
int list2[M] = {5, 6, 4};

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode *Create_1(void){
    ListNode *pre = new ListNode(0);
    ListNode *p = pre;
    for(int i = 0;i < N;i++){
        p->next = new ListNode(list1[i]);
        p = p->next;
    }
    return pre;
}

ListNode *Create_2(void){
    ListNode *pre = new ListNode(0);
    ListNode *p = pre;
    for(int i = 0;i < M;i++){
        p->next = new ListNode(list2[i]);
        p = p->next;
    }
    return pre;
}

ListNode *addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode *preHead = new ListNode(0);
    ListNode *p = preHead;
    int carry = 0; 
    int sum = 0;
    while(l1 || l2 || carry){
        sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
        carry = sum / 10;
        p->next = new ListNode(sum%10);
        p = p->next;
        l1 = l1?l1->next:NULL;
        l2 = l2?l2->next:NULL;
    }
    return preHead->next;
}

void Traversal(ListNode *list){
    ListNode *p = list;
    while(p){
        cout << p->val << "--";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = Create_1();
    ListNode *l2 = Create_2();
    ListNode *l3 = addTwoNumbers(l1,l2);
    Traversal(l3);
    system("pause");
    return 0;
}
