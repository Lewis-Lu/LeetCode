#include <stdio.h>
#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

int reverse(int x) {
    int max_32 = 2147483647;
    int min_32 = -2147483648;

    long ans = 0;
    int sign = 0;
    int i = 0;

    if(x > max_32 || x < min_32) return 0;
    sign = (x>0) - (x<0);
    x = abs(x);
    while(x != 0){
        int res = x % 10;
        x /= 10;
        ans = res + ans*10;
        cout << ans << " " << res << endl;
    }
    if(ans > INT_MAX || ans < INT_MIN) return 0;
    return ans*sign;
}

int main(int argc, char const *argv[])
{
    int a = 1534236469;
    cout << reverse(a) << endl;
    
    return 0;
}
