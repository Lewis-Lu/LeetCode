#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

// divide and conquer
// divide array into two halves
// return max value within following three
// a) max sum in left half
// b) max sum in right half
// c) max sum cross the mid line **(this is the key)

static int count = 0;

class Solution{
private:
    int max(int a, int b){return a>b?a:b;}

    int max(int a, int b, int c){return max(max(a, b), c);}

    int maxSubArray(vector<int>& nums, int l, int r){
        // basic problem
        if(l == r){
            cout <<"output = " << nums[l] << endl;
            return nums[l];
        }
        int m = (l+r)/2;

        return max( maxSubArray(nums, m+1, r), 
                    maxSubArray(nums,l,m), 
                    maxCrossingSum(nums, l , m , r));
    }

    int maxCrossingSum(vector<int>& nums, int l, int m, int r){
        int 
            left_sum = INT_MIN,
            right_sum = INT_MIN,
            sum = 0;
        for(int i = m; i >= l; i--){
            sum += nums[i];
            if(left_sum <= sum) left_sum = sum;
        }

        sum = 0;
        for(int i = m+1; i <= r; i++){
            sum += nums[i];
            if(right_sum <= sum) right_sum = sum;
        }

        return left_sum + right_sum;
    }

public:

    int maxSubArray(vector<int>& nums){
        if(nums.size() == 0) return 0;
        return maxSubArray(nums, 0, nums.size()-1);
    }
};


int main(int argc, char const *argv[]){
    vector<int> data = {1,-10,3,4,-5,3,4,5,6};
    Solution s;
    cout << s.maxSubArray(data) << endl;
    return 0;
}

