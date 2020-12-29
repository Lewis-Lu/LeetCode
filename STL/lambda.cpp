#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Person{
public:
    Person(const std::string& first, const std::string& last):firstName(first), lastName(last){}
    Person() = default;

    std::string first() const {return firstName;}
    std::string last() const {return lastName;}

private:
    std::string firstName;
    std::string lastName;
};

class IntSequence{
public:
    IntSequence(int initVal): value(initVal){}
    int operator() (){return value++;}
private:
    int value;
};

int main(int argc, char const *argv[])
{
    // use lambda as callback function in the STL
    // std::vector<int> v{1, 2, 5, 6, 3, 4, 6, 6};
    // int threshold = 4;
    // int count = std::count_if(v.begin(), v.end(), [threshold](int x){return x > threshold;});
    // std::cout << count << std::endl;

    // add some Person info
    // sort Person using lambda
    // std::vector<Person> pList{Person("Hong", "Lu"), Person("Andrew", "Li")};
    // sort(pList.begin(), pList.end(), [](const Person& a, const Person& b){
    //     return (a.first() < b.first() || (a.first() == b.first() && a.last() < a.last()));
    // });
    // for(auto i:pList) std::cout << i.first() << " " << i.last() << std::endl;

    // full syntax for c++ lambda
    // [capture-list](params) mutable(optional) constexpr(optional) exception attribute -> ret {body}

    // since C++14, generic in lambda in supported.
    // auto add = [](auto a, auto b) {return a+b;};
    // std::cout << add(1.0, 2) << std::endl;

    IntSequence is(0);
    std::vector<int> v(10);
    std::generate(v.begin(), v.end(), IntSequence(0));
    for(auto i:v) std::cout << i << " ";
    std::cout << std::endl;


    return 0;
}
