#include<stdlib.h>
#include<stdio.h>
int main(void){
    
    int count = 3;
    int temp[]={0,0,0,0,0};
    int temp2[]={1,2,3,4,5,6,7,8};
    int *temp3 = temp;
    int *temp4 = temp2;
   // temp2 = malloc(6*sizeof(int));
   // for(int i=0;i<6;i++){
       // temp2[i] = i;
     //   printf("this is init:%d\n",temp[i]);
   // }
//    temp = malloc(3*sizeof(int));
   /* while(count--){
        *temp = *(temp2++);
        *(temp++);
        printf("%d\n",*(temp-1));
    }*/
  //  printf("%p\n",temp4);
//    temp4 = temp4+1;
   // printf("%p\n",temp);
    while(count--){
        temp3 = temp4++;
        temp3++;
        printf("%d\n",*temp3);
    }
}

