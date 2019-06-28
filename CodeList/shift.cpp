#include <stdio.h>
#include <stdlib.h>

typedef unsigned short u16

int main(int argc, char const *argv[]){
    u16 origin = 0x5;
    u16 shift;
    shift = origin << 12;
    printf("Addr: %x\n", &origin);
    printf("Addr: %x\n", &(origin + 1));
    printf("%x\n",shift);
    return 0;
}
