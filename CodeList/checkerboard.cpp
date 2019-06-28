#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

#define mval 0x7fff

using namespace std;

int min(int a, int b){return a<b?a:b;}
int min(int a, int b, int c){return min(min(a, b), c);}


// only can move diagonally left, forward and diagonally right.

vector<vector<int>>map = {{mval,mval,5,mval,mval},{mval,6,7,0,mval},{3,5,7,8,2},{7,6,1,1,4},{6,7,4,7,8}};

int minCost(int i, int j){
    if(i < 0 || j > 4){
        return mval;
    }else if(i == 0){
        return map[i][j];
    }else{
        return min(minCost(i-1,j-1), minCost(i-1,j), minCost(i-1,j+1)) + map[i][j];
    }
}


int main(int argc, char const *argv[]){
    cout << minCost(3,4) << endl;
    return 0;
}
