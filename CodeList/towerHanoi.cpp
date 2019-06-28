#include <stdio.h>
#include <iostream>

using namespace std;

// always follow the sub-problem that 
// 1. move n-1 disk to aux rod
// 2. move the last disk to destination rod
// 3. move n-1 disk to destination rod

void Hanoi(int n, char from, char to, char aux){
    if(n == 1){
        cout << "move 1 from " << from << " to " << to << endl;
        return;
    }
    Hanoi(n-1, from, aux, to);
    // cout << "move " << n << " from " << from << " to " << to << endl;
    Hanoi(n-1, aux, to, from); 
}

int main(int argc, char const *argv[]){
    Hanoi(4,'A','B','C');
    return 0;
}

