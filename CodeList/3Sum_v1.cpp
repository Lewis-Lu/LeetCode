#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> ans;
    int size = nums.size();
    if(size < 3) return ans;

    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < size; i++){
        int a = nums[i];
        if(a > 0) break;
        if(i > 0 && nums[i-1] == a) continue;
        for(int j = i+1, k = size-1; j < k;){
            int b = nums[j];
            int c = nums[k];
            int sum = a + b + c;
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                ans.push_back(vector<int>({a,b,c}));
                while(j<k && b == nums[++j]);
                while(j<k && c == nums[--k]);
            }
        }
    }
    return ans;
}


int main(int argc, char const *argv[]){
    vector<int> num = {0,0,0};
    vector<vector<int>> ans;
    ans = threeSum(num);
    
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
