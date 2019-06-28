#include <iostream>
#include <map>

using namespace std;

map<int, int>table;

int fib(int n){
    // base case
    if(n < 2) return n;

    if(table.find(n) != table.end()) return table[n];

    int res = fib(n-2) + fib(n-1);
    table.insert(make_pair(n, res));
    return res;
}

int main(int argc, char const *argv[])
{
    cout << fib(2) << endl;
    cout << fib(3) << endl;
    cout << fib(4) << endl;
    return 0;
}
