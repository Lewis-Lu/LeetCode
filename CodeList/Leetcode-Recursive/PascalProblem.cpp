#include <iostream>
#include <vector>

using namespace std;

void Traverse(vector<vector<int>> s)
{
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; i++)
    {
        ans[i].resize(i+1);
        ans[i][0] = ans[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
        }
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    vector<vector<int>> a;
    a = generate(5);
    Traverse(a);
    return 0;
}
