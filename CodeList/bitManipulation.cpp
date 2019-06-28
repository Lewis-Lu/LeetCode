#include <stdio.h>
#include <iostream>

using namespace std;

void swap(int a, int b){
    if(a != b){
        a ^= b;
        b ^= a;
        a ^= b; 
    }
}


int main(int argc, char const *argv[]){
    int b = 10;
    int& a = b; 
}

