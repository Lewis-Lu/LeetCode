#include <iostream>

using namespace std;

class Solution{
public:
    double Power(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        } else if (base == 0) {
            return 0;
        }
        long long p = abs((long long)exponent);
        double r = 1.0;
        while (p) {
            if (p&1) {
                r*=base;
            }
            base *= base;
            p = p>>1;
        }
        return (exponent > 0) ? r : 1/r;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.Power(2.1, 2) << endl;
    return 0;
}
