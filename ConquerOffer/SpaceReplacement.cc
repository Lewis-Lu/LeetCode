#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
	void replaceSpace(char *&str,int length) {
        int space_ctn = 0;
        for (int i = 0; i < length; i++)
            if (str[i] == ' ') 
                space_ctn++;

        char *buffer = (char*)malloc(sizeof(char) * (space_ctn*2 + length));
        strcpy(buffer, str);
        
        for (int i = length-1; i >= 0; i--)
        {
            if (buffer[i] == ' ')
            {
                space_ctn--;
                buffer[i + 2*space_ctn] = '%';
                buffer[i + 2*space_ctn + 1] = '2';
                buffer[i + 2*space_ctn + 2] = '0';
            } 
            else
            {
                buffer[i + 2*space_ctn] = buffer[i];
            }
        }
        
        str = buffer;
	}
};

int main(int argc, char const *argv[])
{
    Solution s;
    char *a = "We Are Happy";
    s.replaceSpace(a, 13);
    cout << a << endl;
    return 0;
}
