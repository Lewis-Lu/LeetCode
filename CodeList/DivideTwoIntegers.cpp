#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

// this question must use divide and conquer solution
// time : O(logN)

// int divide(int dividend, int divisor){
//     int sign = (dividend < 0 || divisor < 0) ? -1 : 1;
//     long ldividend = abs(long(dividend));
//     long ldivisor = abs(long(divisor));

//     if(ldividend == 0 || ldividend < ldivisor) return 0;

//     int count = 0;
//     while(ldividend >= ldivisor){
//         ldividend -= ldivisor;
//         count++;
//     }
//     return sign * count;
// }

int divide(int dividend, int divisor){
    int sign = ((dividend < 0 && divisor > 0)||(dividend > 0 && divisor < 0))?-1:1;
    long nominator = abs(long(dividend));
    long denominator = abs(long(divisor));

    // judge res == 0
    if(nominator == 0 || nominator < denominator) return 0;

    long multiple = 1;
    while(nominator >= multiple*denominator){
        multiple *= 2;
    }

    if(multiple >= INT32_MAX && divisor == 1){
        return INT32_MIN;
    }else if(multiple > INT32_MAX && divisor == -1){
        return INT32_MAX;
    }

    //get last position
    multiple /= 2;

    int res = (nominator - denominator*multiple)/denominator;
    
    res += multiple;

    return sign*res;
}


int main(int argc, char const *argv[]){
    int a = INT32_MIN;
    int b = 1;
    cout << divide(a,b) << endl;
    return 0;
}

