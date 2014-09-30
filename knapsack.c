#include<stdlib.h>
#include<stdio.h>
#define Random(x)(rand()%x)

void print_item(int** array,int row,int column){
//function:print array.
//input:row and column is 2-dimension array index and subindex.
//output:list.
    int i,j;
    for(i=0;i<row;i++){
        printf("item%d:",i+1);
        for(j=0;j<column;j++)
            printf("%d ",array[i][j]);
        printf("\n");

    }

}

int** item_list(int number,int flag){
//function:A set a items of goods,and weight of goods.
//input:Number is number of goods and flag as judge input fashion.
//output:one list contain weight and value of goods.
    int i;
    int** item_set;
    item_set = malloc(number*sizeof(int*));
    for(i=0;i<number;i++)
        item_set[i]=malloc(2*sizeof(int));

    if(flag==1){//you will hand input number if flag=1.
        printf("Please input weight and value:\n");
        for(i=0;i<number;i++){
            printf("goods %d:\n",i+1);
            scanf("%d",&item_set[i][0]);
            scanf("%d",&item_set[i][1]);
    
        }


    }else{
        printf("well,we will auto produce goods random.\n");
        for(i=0;i<number;i++){
            printf("goods%d:",i+1);
            item_set[i][0]=Random(10);
            item_set[i][1]=Random(20);
    
         }

    }

    return item_set;
}


int** dynamic_table(int** goods,int goods_num,int knapsack_capacity){
//function:It will be produce a table which is dynamic program table.
//input:gooods is a set as any goods that contain weight and value,knapsack_capacity is knapsack capacity.
//output:one dynamic program table which is contain optimal solves.
    int i,j;
    int** dynamic_table;
    int temp;
    dynamic_table = malloc((goods_num+1)*sizeof(double*));
    for(i=0;i<=goods_num;i++)
        dynamic_table[i]=malloc((knapsack_capacity+1)*sizeof(double));
    

    for(i=1;i<=goods_num;i++){
        for(j=1;j<=knapsack_capacity;j++){
            if(j-goods[i-1][0]>=0){
                temp = goods[i-1][0];
                if(dynamic_table[i-1][j]>(goods[i-1][1]+dynamic_table[i-1][j-temp])){
                    dynamic_table[i][j]=dynamic_table[i-1][j];
                }else{
                    dynamic_table[i][j]=goods[i-1][1]+dynamic_table[i-1][j-temp];
                }
            
            }else{
                dynamic_table[i][j]=dynamic_table[i-1][j];
            }            
        }
    
    
    }
    return dynamic_table;
}

int main(){
    int number,knapsack_capacity;
    int **goods_item,**goods_optimal;
    printf("Please input capacity of knapsack:\n");
    scanf("%d",&knapsack_capacity);
    printf("Please input number of goods:\n");
    scanf("%d",&number);
    goods_item = item_list(number,0);
    printf("Following is your input:\n");
    print_item(goods_item,number,2);

    goods_optimal = dynamic_table(goods_item,number,knapsack_capacity);
    printf("Following is daynamic list:\n");
    print_item(goods_optimal,number+1,knapsack_capacity+1);
    
    return 0;
}


