#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution{
    public:
    bool 
    Find(int target, vector<vector<int> > array) {
        if(!array.size()) return false;
        for (int i = array.size()-1; i >= 0; i--) {
            if (array[i].size() == 0 || array[i][0] > target)
                continue;
            for (int j = 0; j < array[i].size(); j++){
                if (array[i][j] == target) {
                    cout << i << " " << j << endl;
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int> >a = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9}};
    Solution s;
    s.Find(3, a);
    return 0;
}
