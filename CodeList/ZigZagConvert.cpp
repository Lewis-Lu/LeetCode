#include <stdio.h>
#include <iostream>
#include <string>
 
using namespace std;

string convert(string s, int numRows){
    string ans[numRows];
    string fool = "";
    int index = 0;

    if(s.size() <= numRows || numRows == 1) return s;
    
    for(int i = 0; i < s.size(); i++){
        
        index = i % (2*numRows - 2);
        
        if(index < numRows) ans[index] += s[i];
        else{
            ans[2*numRows-2-index] += s[i];
        }
    }

    for(int i = 0; i < numRows; i++){
        fool += ans[i];
    }
    return fool;
}

int main(int argc, char const *argv[]){
    string a = "PAYPALISHIRING";

    cout << convert(a,3) << endl;
    return 0;
}
