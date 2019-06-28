#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution{
private:

    unordered_map<int, int> map;
    unordered_map<int, int>::iterator uiter;

    void majorityElement(vector<int>& nums, int l, int h){
        int m = (l + h)/2;
        // update key-value;
        if(l == h){
            uiter = map.find(nums[l]);
            if(uiter != map.end()){
                uiter->second++;
            }else{
                map.insert(make_pair(nums[l],1));
            }
            return;
        }

        majorityElement(nums, l, m);
        majorityElement(nums, m+1, h);
    }
public:
    int majorityElement(vector<int>& nums){
        majorityElement(nums, 0, nums.size() - 1);
        for(auto &i : map){
            if(i.second > nums.size()/2){
                return i.first;
            }
        }
        return 0;
    }
};


int main(int argc, char const *argv[]){
    vector<int> nums = {3,2,3};
    Solution s;
    cout << s.majorityElement(nums) << endl;
    return 0;
}
