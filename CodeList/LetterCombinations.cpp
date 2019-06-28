#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> letterCombinations(string digits) {
    vector<string> ans;
    
    if(digits.empty()) return vector<string>();

    static const vector<string> str = {"", "", "abc", "def", "hij", "klm", "nop", "qrs", "tuv", "wxyz"};
    
    ans.push_back("");
    
    for(int i = 0; i < digits.size(); i++){
        int nums = digits[i] - '0';
        if(nums < 2 || nums > 9) break;
        const string& to_create = str[nums];
        vector<string> tmp;
        for(int j = 0; j < to_create.size(); j++){
            for(int k = 0 ; k < ans.size(); k++){
                tmp.push_back(ans[k] + to_create[j]);
            }
        }
        ans.swap(tmp);
    }
    return ans;
}

int main(int argc, char const *argv[]){
    
    return 0;
}
