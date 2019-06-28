#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindromic(string s, int beg, int end){
    int len = end - beg + 1;
    string str = s.substr(beg, len);
    
    for(int k = 0; k < len/2; k++){
        if(str[k] != str[len-1-k]) return false;
    }

    return true;
}


string longestPalindrome(string s){
    string ans_str;
    int len = s.size();
    int ans_max = 0;
    int i_save = 0, j_save = 0;

    if(len == 0) return "";
    if(len == 1) return s;

    for(int k = 0; k < len; k++){
        for(int t = k+ans_max; t < len; t++){
            if(IsPalindromic(s,k,t)){                
                if(ans_max < (t-k+1)){
                    ans_max = t-k+1;
                    i_save = k;
                    j_save = t;
                }
            }
        }
    }
    cout << i_save << " " << j_save << endl;
    return s.substr(i_save, j_save-i_save+1);
}

int main(void){
    string a = "babad";
    string b = "cbbd"; 
    cout << longestPalindrome(b) << endl;
    cout << longestPalindrome(a) << endl;
    system("pause");
    return 0;
}