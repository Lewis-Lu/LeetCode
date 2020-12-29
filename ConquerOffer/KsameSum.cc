#include <iostream>
#include <vector>

using namespace std;

class KsameSum{
private:

public:
    bool sameSum(vector<int> num, int k) {
        int sum = 0;
        for (vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) {
            sum += *iter;
        }
        if (sum % num.size() != 0) return false;
        auto avg = sum / num.size();
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
