#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> tail2head, head2tail;
        ListNode* p = head;
        while (p)
        {
            head2tail.push_back(p->val);
            p = p->next;
        }
        while (!head2tail.empty())
        {
            tail2head.push_back(head2tail[head2tail.size()-1]);
            head2tail.pop_back();
        }
        return tail2head;
    }
};