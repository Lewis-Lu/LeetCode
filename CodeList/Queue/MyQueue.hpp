#include <iostream>

using namespace std;

class MyQueue{
private:
    int* queue;
    int capacity;
    int front;
    int rear;
    int count;

public:
    MyQueue(int size);
    bool push(int val);
    int pop();
    bool Empty();
    void Tranverse();
};

MyQueue::MyQueue(int size){
    queue = new int[size];
    capacity = size;
    front = count = 0;
    rear = -1;
}

bool MyQueue::Empty(){
    if(count == 0){
        return true;
    }else{
        return false;
    }
}

bool MyQueue::push(int val){
    if(count == capacity) return false;
    queue[(++rear) % capacity] = val;
    count++;
    return true;
}

int MyQueue::pop(){
    if(count == 0) exit(EXIT_FAILURE);
    int res = queue[(++front) % capacity];
    count--;
    return res;
}

void MyQueue::Tranverse(){
    if(count == 0) return;
    int k = front;
    for(int i = 0; i < count; i++){
        cout << queue[k] << " ";
        k = (k+1)%capacity;
    }
    cout << endl;
}

