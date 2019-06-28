#include <stdio.h>
#include <string>
#include <set>
#include <iostream>

using namespace std;

typedef set<char> Myset;
typedef set<char>::iterator Siter;

void Traversal(Myset s){
    for(Siter iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

int LengthofSubstring(string s){
    // initalization
    int preWin = 0, endWin = 0;
    int L = s.length();
    int ans = 0;
    Myset Set;
    Siter iter;

    // solution
    if(s.length() < 2) return s.length();

    while(preWin < L && endWin < L){
        if(Set.find(s[endWin]) == Set.end()){
            Set.insert(s[endWin++]);
            ans = (ans < endWin - preWin)?(endWin - preWin):ans;
        }else{
            Set.erase(s[preWin++]);
        }
        Traversal(Set);
        cout << ans << endl;
    }
    return ans;
}


int main(void){
    string a = "bbbbb";
    string b = "abcabcbb";
    string c = "";

    cout << LengthofSubstring(b) << endl;
    
    system("pause");
    return 0;
}