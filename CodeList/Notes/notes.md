# Practice Notes

## Mistake Correction
* malloc + free

```C 
Problem
#define SIZE 100

void allocate_mem(char* str, int size){
    str = (char*)malloc(size);
}

void test(){
    char* str = null;
    allocate_mem(str, SIZE);
    strcpy(str, "Hello");
    printf(str);
}
```
**what's the problem and how to correct it?**
```C
void allocate_mem(char* str, int size){
    if(!malloc(size)) return;
    str = malloc(size);
}

void test(){
    char* str = null;
    allocate_mem(str, SIZE);
    strcpy(str, "Hello");
    printf(str); 
    free(str);
}   
```


