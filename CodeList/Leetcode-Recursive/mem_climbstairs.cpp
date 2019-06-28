// basically it's a fibonacci problem

#include <iostream>
#include <map>

using namespace std;

// stair, ways
map<int, int> table;

int climbStairs(int n)
{
    if(n <= 2) return n;

    if(table.find(n) != table.end()) return table[n];

    int res = climbStairs(n-1) + climbStairs(n-2);
    table.insert(make_pair(n, res));
    
    return res;
}

int main(int argc, char const *argv[])
{   
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;
    return 0;
}
