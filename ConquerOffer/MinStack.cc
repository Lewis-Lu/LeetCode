#include <iostream>
#include <stack>

using namespace std;

class minStack {
    private:
        stack<int> stk1;
        stack<int> stk2;
    public:
        void push(int x) {
            if (stk2.empty() || x <= stk2.top()) {
                stk2.push(x);
                stk1.push(x);
            } else {
                stk1.push(x);
            }
        }

        int pop(void) {
            int ans = 0;
            if (stk1.top() == stk2.top()) {
                ans = stk1.top();
                stk1.pop();
                stk2.pop();
            } else {
                ans = stk1.top();
                stk1.pop();
            }
            return ans;
        }

        int min(void) {
            return stk2.top();
        }
};


int main(int argc, char const *argv[])
{
    minStack ms;
    ms.push(5);
    ms.push(4);
    ms.push(3);
    ms.push(5);
    ms.push(2);
    cout << ms.min() << endl;
    ms.pop();
    cout << ms.min() << endl;
    ms.pop();
    ms.pop();
    cout << ms.min() << endl;
    return 0;
}
