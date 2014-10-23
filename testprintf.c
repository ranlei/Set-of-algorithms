#include<stdio.h>

int main(){
    struct x {int a;int b;char c;};
    struct y {int a;char c;int b;char m;};
    printf("x=%d\n",sizeof(struct x));
    printf("y=%d\n",sizeof(struct y));
}
