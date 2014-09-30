　　　#include<stdio.h>
　　　#include<stdlib.h>
　　　#include<time.h>
　　　#include<unistd.h>
　　　int recursive_fabnacci(int n){
　　　    if(n<=1){
　　　        return n;
　　　    }else{
　　　        return recursive_fabnacci(n-1)+recursive_fabnacci(n-2);
　　　    }
　　　
　　　
　　　}
　　　int nonrecursive_fabnacci(int n){
　　　    int i,fab1=1,fab2=1;
　　　    if(n<=1){
　　　        return n;
　　　    }else if(n==2){
　　　        return 1;
　　　    }else{
　　　
　　　        for(i=2;i<n;i++){
　　　            fab2 = fab1+fab2;
　　　            fab1 = fab2-fab1;
　　　        }
　　　        return fab2;
　　　    }
　　　
　　　}
　　　int max_fab_num(int (*function)(int)){  //calculate the maximum number of function 
　　　   int sys_bit = sizeof(void*)*8;
　　　   int i=0,maximum=0;
　　　   FILE* f;
　　　  // f = fopen("./test.txt","wt");
　　　   while(0<=maximum && maximum<=2^sys_bit){
　　　       maximum = function(i);
　　　     //  fprintf(f,"%d %d",i,maximum);
　　　    //   printf("%d\n",maximum);
　　　       i++;
　　　   } 
　　　  // close(f);
　　　    return i-1;
　　　
　　　
　　　
　　　}
　　　
　　　
　　　int main(){
　　　    int n=40,i=0;
　　　    clock_t start1,start2,end1,end2;
　　　    double retime,nonretime;
　　　    start1 = clock();
　　　   // for(i=0;i<n;i++){
　　　       //  printf("%d\n",nonrecursive_fabnacci(i));
　　　
　　　        printf("迭代计算：最大的Fabnacci是第%d位。\n",max_fab_num(recursive_fabnacci));
　　　   // }
　　　    end1 = clock();
　　　    start2 = clock();
　　　   // for(i=0;i<n;i++){
　　　     //  printf("%d\n",recursive_fabnacci(i));
　　　
　　　   
　　　     printf("递归计算：最大的fabnacci是第%d位。\n",max_fab_num(nonrecursive_fabnacci));
　　　   // }
　　　    end2 = clock();   
　　　    
　　　    nonretime = (double)(end1-start1);
　　　    printf("recursive time:%f\n",nonretime);
　　　 
　　　    retime = (double)(end2-start2);
　　　    printf("nonrecursive time:%f\n",retime);
　　　
　　　    return 0;
　　　}           

