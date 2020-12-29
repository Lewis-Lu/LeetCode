#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<int> even;
    vector<int> odd;
public:
    void reOrderArray(vector<int> &array) {
        for (auto i : array)
        {
            if (i%2) {
                odd.push_back(i);
            }else{
                even.push_back(i);
            }
        }
        for (auto i : even) {
            odd.push_back(i);
        }
        array = odd;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> array = {1,2,3,4,5,6,7,7,8};
    s.reOrderArray(array);
    for (auto i : array) {
        cout << i << " ";
    }
    return 0;
}
