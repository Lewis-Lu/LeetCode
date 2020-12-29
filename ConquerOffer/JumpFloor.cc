#include <iostream>
#include <map>
#include <math.h>

using namespace std;

class Solution{
typedef map<int, int> table_type;

private:
    table_type table;

public:
    int jumpFloor(int number) {
        if(number == 1 || number == 2)
            return number;
        
        for (table_type::iterator iter = table.begin(); iter != table.end(); iter++) {
            if (iter->first == number)
                return iter->second;
        }

        table.insert({number, jumpFloor(number-1) + jumpFloor(number-2)});
        table_type::iterator itr = table.find(number);
        return itr->second;
    }

    int jumpFloorII(int number) {
        return pow(2, number-1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.jumpFloor(4) << endl;
    return 0;
}
