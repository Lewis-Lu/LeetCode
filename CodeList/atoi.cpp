#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str){
    int i = 0;
    long long int ans = 0;
    int sign = 1;
    //deal with whitespace
    while(str[i] == ' '){
        i++; 
    }
    //deal with sign and first word
    if(str[i] == '-'){
        sign = -1;
        i++;
    }else if((str[i]>64 && str[i] < 91 )||(str[i]>96 && str[i] < 123)){
        return 0;
    }else if (str[i] == '+'){
        sign = 1;
        i++;
    }else sign = 1;
    
    while(str[i] > 47 && str[i] < 58){
        ans = 10*ans + str[i] - '0';
        if(ans*sign < INT_MIN) return INT_MIN;
        if(ans*sign > INT_MAX) return INT_MAX;
        i++;
    }
    return ans*sign;
}

int main(int argc, char const *argv[])
{
    string a = "-91283472332";
    cout << myAtoi(a) << endl;
    return 0;
}
