// longest increase subsequence
#include <iostream>
#include <vector>

using namespace std;

int f(vector<int>& num, int j) {
    int a = 1;
    for(int i = 0; i < j; i++) {
        if(num[i] < num[j])
            a = max(f(num, i) + 1, a);
    }
    return a;
}

int f_dp(vector<int>& num, int j, vector<int>& dp) {
    if(dp[j] != -1) return dp[j];
    int a = 1;
    for(int i = 0; i < j; i++) {
        if(num[i] < num[j])
            a = max(f(num, i) + 1, a);
    }
    dp[j] = a;
    return dp[j];
}


int main(int argc, char const *argv[])
{
    vector<int> a{10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> dp{-1, -1, -1, -1, -1, -1, -1, -1};
    int ans = f_dp(a, 7, dp);
    cout << "length of longest increase subsequence is " << ans << endl;
    return 0;
}
