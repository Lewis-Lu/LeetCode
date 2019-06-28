#include<stdio.h>
#include<iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s){
    if(s.length()%2) return false;
    stack <char> stk;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stk.push(s[i]);
        }else if(s[i] == ')' && !stk.empty()){
            if(stk.top() != '(') return false;
            else stk.pop();
        }else if(s[i] == ']' && !stk.empty()){
            if(stk.top() != '[') return false;
            else stk.pop();
        }else if(s[i] == '}' && !stk.empty()){
            if(stk.top() != '{') return false;
            else stk.pop();
        }else{
            return false;
        }
    }
    if(!stk.empty()) return false;
    return true;
}

int main(int argc, char const *argv[]){
    string s = "((";
    cout << isValid(s);
    return 0;
}
