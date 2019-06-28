#include <iostream>
#include <stdio.h>

using namespace std;

static int count = 0;

int fib(int n){
    cout << ++count << endl;
    if(n <= 1) return n;
    return fib(n-1)+ fib(n-2);
}

int main(int argc, char const *argv[]){
    int a = fib(5);
    cout << a << endl;
    return 0;
}
