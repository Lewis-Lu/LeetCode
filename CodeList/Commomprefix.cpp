#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    if(strs.size() == 0) return ans;
    for(int i = 0; i < strs[0].length(); i++){
        for(int j = 1; j < strs.size(); j++){
            if(strs[0][i] != strs[j][i]) return ans;
            
        }
        ans += strs[0][i];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

