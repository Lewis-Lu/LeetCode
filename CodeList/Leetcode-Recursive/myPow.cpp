#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

double myPow(double x, long n)
{
    if(n == 0) return 1;
    
    if(n < 0){
        x = 1/x;
        n = -n;
    }
    return (n%2 == 0)? pow(x*x,n/2) : x*pow(x*x, n/2);
}


int main(int argc, char const *argv[])
{   
    cout << myPow(2.00, -2) << endl;
    return 0;
}
