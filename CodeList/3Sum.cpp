#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int sum2 = 0;
    vector<int> triplet(3, 0);
    for(int i = 0; i < nums.size(); i++){
        sum2 = -nums[i];
        for(int j = i+1; j < nums.size(); j++){
            for(int k = j+1; k < nums.size(); k++){
                if(nums[j] + nums[k] == sum2){
                    triplet[0] = nums[i];
                    triplet[1] = nums[j];
                    triplet[2] = nums[k];
                    sort(triplet.begin(), triplet.end());
                    ans.push_back(triplet);
                }
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        for(int j = ans.size()-1; j >= i+1; j--){
            if(ans[i][0] == ans[j][0] && ans[i][1] == ans[j][1] && ans[i][2] == ans[j][2]) ans.erase(ans.begin() + j);
        }
    }
    return ans;
}


int main(int argc, char const *argv[]){
    vector<int> num = {4,-9,-13,-9,0,-12,12,-14,12,1,3,5,5,8,2,-2,8,1,2,-6,-6,1,6,-15,-2,7,-11,3,-2,1,11,10,8,14,8,-15,9,5,-14,6,14,-3,-12,4,-10,5,-12,13,14,-3,-15,-7,5,-2,-15,10,-10,11,-2,-5,-2,-5,-10,13,-14,14,13,2,4,7,-6,3,11,-3,-15,-14,10,10,6,1,-8,-2,1,12,11,1,7,8,-10,13,-11,3,-15,-6,-7,8,-7,13,-5,5,-3,4,-15,-7,9,-15,-14,-4,2,0,4,9,13,-10,-2,10};  
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
