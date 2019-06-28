#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtracking(vector<string> &v, string str, int n, int m, int max){
    // goal
    if(n + m == 2*max){
        v.push_back(str);
        return;
    }
    if(n < max) {backtracking(v, str+'(',n+1, m, max);}
    if(m < n) {backtracking(v, str+')', n, m+1, max);}
}

vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking(res, "", 0, 0, n);
        return res;
}

int main(int argc, char const *argv[]){
    vector<string> ans = generateParenthesis(3);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}
