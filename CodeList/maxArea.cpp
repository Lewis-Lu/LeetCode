#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int maxArea(vector<int>& height){
    int ans = 0;
    if(height.size() == 2) return (height[0] < height[1])?height[0]:height[1];
    for(int i = 0; i < height.size(); i++){
        for(int j = i + 1; j < height.size();j++){ 
            int h = (height[i] < height[j]) ? height[i] : height[j];
            ans = (ans > (j-i)*h) ? ans : (j-i)*h;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> a{1,8,6,2,5,4,8,3,7};
    cout << maxArea(a) << endl;
    
    return 0;
}
