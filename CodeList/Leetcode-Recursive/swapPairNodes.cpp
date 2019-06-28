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
    ListNode* swapPairs(ListNode* head){
        // base case
        if(NULL == head || NULL == head->next) return head;

        // ordinary operation
        ListNode* newhead = head->next;
        head->next = swapPairs(head->next->next);
        newhead->next = head;

        return newhead;
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
    ListNode* e = new ListNode(5);
    ListNode* root = a;
    a->next = b;
    b->next = c;
    c->next = d;
    // d->next = e;

    Solution s;
    s.Traverse(root);
    cout << "After swap"  <<endl;
    root = s.swapPairs(root);
    s.Traverse(root);
    return 0;
}
