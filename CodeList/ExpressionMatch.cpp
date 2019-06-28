#include <stdio.h>
#include <iostream>

using namespace std;

bool isMatch(string s, string p) {
    bool dp[s.length() + 1][p.length() + 1];
    dp[0][0] = true;

    for(int i = 1; i <= p.length(); i++){
        if(p[i-1] == '*' && dp[0][i-2]) dp[0][i] = true;
    }

    for(int i = 1; i <= s.length(); i++){
        for(int j = 1; j <= p.length(); j++){
            // if judge two char equal
            if(s[i-1] == p[j-1] || p[j-1] == '.'){
                dp[i][j] = dp[i-1][j-1];
            // else if judge *
            }else if (p[j-1] == '*') {
                if(s[i-1] != p[j-2] && p[j-2] != '.'){
                    dp[i][j] = dp[i][j-2]; 
                }else{
                    dp[i][j] = (dp[i][j-2] || dp[i][j-1] || dp[i-1][j]);
                }
            }
        }
    }
    return dp[s.length()][p.length()];
}

int main(int argc, char const *argv[])
{
    string s = "aab";
    string p = "c*a*b";
    cout << isMatch(s,p) << endl;
    return 0;
}
