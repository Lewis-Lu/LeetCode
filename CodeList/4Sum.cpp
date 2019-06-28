#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include <math.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    vector<vector<int>> ans;
    if(nums.size() < 4) return vector<vector<int>>();

    sort(nums.begin(), nums.end());

    for(int i = 0, j = nums.size()-1; j-i+1 >= 4;){
        int a = nums[i];
        int b = nums[j];
        int p = i+1, q = j-1;
        while(p < q){
            int sum = nums[i] + nums[j] + nums[p] + nums[q];
            if(sum == target){
                vector<int> tmp(4,0);
                tmp[0] = nums[i];
                tmp[1] = nums[p];
                tmp[2] = nums[q];
                tmp[3] = nums[j];
                for(int k = 0; k < 4;k++) cout << tmp[k] << " ";
                cout << endl;
                ans.push_back(tmp);
            }
            if(sum < target) p++;
            else q--;
        }
        while(a == nums[++i]);
        while(b == nums[--j]);
    }
    return ans;
}

int main(int argc, char const *argv[]){
    vector<int> a = {0,0,0,0};
    vector<vector<int>> ans = fourSum(a,0);

    return 0;
}
