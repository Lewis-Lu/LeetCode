#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include <math.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target){
    int ans = 0, res = INT_MAX;
    int size = nums.size();
    sort(nums.begin(), nums.end());    
    
    for(int i = 0; i < size-2; i++){
        int j = i + 1;
        int k = size - 1;

        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(abs(sum - target) < res){
                res = abs(sum - target);
                ans = sum;
                while(nums[j+1] == nums[j]) j++;
                j++;
                while(nums[k-1] == nums[k]) k--;
                k--;
            }
        }
    }
    return ans;
}


int main(int argc, char const *argv[]){
    vector<int> nums = {0,0,0};
    int target = 1;
    cout << threeSumClosest(nums, target);    
    return 0;
}
