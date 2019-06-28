#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) {
    vector<int> tmp;
    vector<int>::iterator i;
    vector<int>::iterator j;

    int res = 0;
    
    if(x < 0) return false;
    if(x >= 0 && x < 10) return true;

    while(x != 0){
        res = x%10;
        x = x/10;
        tmp.insert(tmp.end(),res);
    }

    for(i = tmp.begin(), j = tmp.end()-1;i <= j;i++,j--){
        if(*i != *j) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cout << isPalindrome(10) << endl;
    return 0;
}