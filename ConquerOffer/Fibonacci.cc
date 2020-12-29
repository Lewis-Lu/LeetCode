// Fibonacci with memorible of course!!!

#include <iostream>
#include <map>


using namespace std;

class Solution {
private:
    map<int, int> table;
public:
    int Fibonacci(int n) {
        if(n == 0 || n == 1) {
            return n;
        }

        for(map<int, int>::iterator iter = table.begin(); iter != table.end(); iter++) {
            if (iter->first == n) {
                return iter->second;
            }
        }

        table.insert({n, (Fibonacci(n-1)+Fibonacci(n-2))});

        auto itr = table.find(n);
        return itr->second;
    }
};
