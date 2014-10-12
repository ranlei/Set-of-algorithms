#include<stdlib.h>
#include<stdio.h>
union testdaduan{
    int a;
    char b;
};
typedef union testdaduan test;
int main(void){
    test d;
    d.a=1;
    printf("%s\n",d.b==1?"daduan":"xiaoduan");

    printf("%p\n",&d.a);
    printf("%p\n",&d.b);
    static int m;
    printf("%p\n",&m);
    while(1);    
    return 0;
}
