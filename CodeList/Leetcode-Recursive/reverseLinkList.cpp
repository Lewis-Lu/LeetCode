#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x){val = x; next = NULL;}
};

class Solution
{
private:

public:
    ListNode* reverseLinkedList(ListNode* head){
        if(NULL == head || NULL == head->next) return head;

        ListNode* s = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return s;
    }
    
    void Traverse(ListNode* head){
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);

    
    ListNode* root = a;
    a->next = b;
    b->next = c;
    c->next = d;


    Solution s;
    s.Traverse(root);
    s.Traverse(s.reverseLinkedList(root));

    return 0;
}
