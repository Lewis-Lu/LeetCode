#include "MyQueue.hpp"

int main(int argc, char const *argv[])
{
    MyQueue q(2);
    q.push(1);
    q.push(2);
    q.pop();
    q.Tranverse();

    return 0;
}
