#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define NUM1 5
#define NUM2 0

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    int counter = 0;
    double even_out = 0.0;

    vector<int>::iterator i = nums1.begin();
    vector<int>::iterator j = nums2.begin();

    cout << len << endl;

    if(nums1.size() == 0){
        if(nums2.size()%2){
            //odd
            return *(nums2.begin() + (nums2.size()/2));
        }else{
            return (*(nums2.begin() + (nums2.size()/2-1)) + *(nums2.begin() + (nums2.size()/2)))/2.0;
        }
    }else if(nums2.size() == 0){
        if(nums1.size()%2){
            //odd
            return *(nums1.begin() + (nums1.size()/2));
        }else{
            return (*(nums1.begin() + (nums1.size()/2-1)) + *(nums1.begin() + (nums1.size()/2)))/2.0;
        }
    }
    
    if(len%2){
        while(1){
            if(*i <= *j){
                cout << "[" << 1 << "] = " << *i << endl; 
                counter++;
                i++;
                if(counter == len/2) return *i;
                
                
            }else{
                cout << "[" << 2 << "] = " << *j << endl; 
                counter++;
                j++;
                if(counter == len/2) return *j;
                
                
            }
        }
        
    }else{
        //even
        int f,s = 0; //first second integer
        while(1){
            if(*i <= *j){
                cout << "[" << 1 << "] = " << *i << endl; 
                counter++;
                i++;
                if(counter == len/2 - 1){
                    f = *i;
                }else if(counter == len/2){
                    s = *i;
                    even_out = (f + s)/2.0;
                    return even_out;
                }
                
                
            }else{
                cout << "[" << 2 << "] = " << *j << endl;
                counter++;
                j++;
                if(counter == len/2 - 1){
                    f = *j;
                }else if(counter == len/2){
                    s = *j;
                    even_out = (f + s)/2.0;
                    return even_out;
                }
                
                
            }
        }
    }
}

int main(void){
    int num1[5] = {1,2,3,3,4};
    int num2[4] = {4,5,6,4};
    vector<int> nums1(num1,num1+NUM1);
    vector<int> nums2(num2,num2+NUM2);
    double a = findMedianSortedArrays(nums1,nums2);
    cout << a << endl;
    system("pause");
    return 0;
}