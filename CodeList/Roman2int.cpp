#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int romanToInt(string s) {
    int sum = 0;
    map<char, int> T = {{ 'I' , 1 },
                        { 'V' , 5 },
                        { 'X' , 10 },
                        { 'L' , 50 },
                        { 'C' , 100 },
                        { 'D' , 500 },
                        { 'M' , 1000 }};

    for(int i = s.length()-1; i >= 0; i--){
        if(T[s[i]] < T[s[i+1]]) sum-=T[s[i]];
        else{
            sum += T[s[i]];
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
