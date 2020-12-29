#include <iostream>
#include <vector>

using namespace std;


struct p2d
{
    p2d(int x_, int y_): x(x_), y(y_) {} 

    int x, y;

    void print(void) {std::cout << x << " " << y << std::endl;}
};

void swapInPair(vector<int>& nums) {
    if(nums.size() < 2) return;
    for(vector<int>::iterator f = begin(nums), r = f+1, e = end(nums); r < e; f+=2, r+=2) {
        swap(*f, *r);
    }
}

int main(int argc, char const *argv[])
{
    // vector<int> a{1,2,3,4,5,6};
    // swapInPair(a);
    // for(auto const& v:a) 
    //     cout << v << " ";

    vector<p2d> s{p2d(1,2)};
    s.push_back(p2d(2,3));
    s.emplace(begin(s)+1, p2d(3,4)); // c++ 11 insert&construct elements in-place
    s.emplace_back(p2d(6,7)); // emplace back

    for(auto v:s){
        v.print();
    }

    
    return 0;
}
