#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<int> Viter;

vector<int> TwoSum(vector<int> &numbers, int target){
        unordered_map<int, int> hash;
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++){
            int number_to_find = target - numbers[i];
            if(hash.find(number_to_find) != hash.end()){
                return{hash[number_to_find],i};
            }
            hash[numbers[i]] = i;
        }
        return {};
}

int main(){
    int raw[4] = {2,7,11,15};
    vector<int> all;
    all.insert(all.begin(), raw, raw+5);
    vector<int>result = TwoSum(all,9);
    for(Viter::const_iterator iter = result.begin(); iter != result.end(); iter++){
        cout << *iter << " ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
